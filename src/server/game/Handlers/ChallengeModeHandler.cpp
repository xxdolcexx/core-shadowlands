/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#include "ChallengeModePackets.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Log.h"
#include "Group.h"
#include "Player.h"
#include "WorldSession.h"
#include "Chat.h"
#include "ChallengeModeMgr.h"
#include <Challenge.h>


void WorldSession::HandleRequestLeaders(WorldPackets::ChallengeMode::RequestLeaders& packet)
{
    WorldPackets::ChallengeMode::RequestLeadersResult result;
    result.MapID = packet.MapId;
    result.ChallengeID = packet.ChallengeID;

    result.LastGuildUpdate = time(nullptr);
    result.LastRealmUpdate = time(nullptr);

    if (auto bestGuild = sChallengeModeMgr->BestGuildChallenge(_player->GetGuildId(), packet.ChallengeID))
    {
        for (auto itr = bestGuild->member.begin(); itr != bestGuild->member.end(); ++itr)
        {
            WorldPackets::ChallengeMode::ModeAttempt guildLeaders;
            guildLeaders.InstanceRealmAddress = GetVirtualRealmAddress();
            guildLeaders.AttemptID = bestGuild->ID;
            guildLeaders.CompletionTime = bestGuild->RecordTime;
            guildLeaders.CompletionDate = bestGuild->Date;
            guildLeaders.MedalEarned = bestGuild->ChallengeLevel;

            for (auto const& v : bestGuild->member)
            {
                WorldPackets::ChallengeMode::ModeAttempt::Member memberData;
                memberData.VirtualRealmAddress = GetVirtualRealmAddress();
                memberData.NativeRealmAddress = GetVirtualRealmAddress();
                memberData.Guid = v.guid;
                memberData.SpecializationID = v.specId;
                guildLeaders.Members.emplace_back(memberData);
            }

            result.GuildLeaders.emplace_back(guildLeaders);
        }
    }

    if (ChallengeData* bestServer = sChallengeModeMgr->BestServerChallenge(packet.ChallengeID))
    {
        WorldPackets::ChallengeMode::ModeAttempt realmLeaders;
        realmLeaders.InstanceRealmAddress = GetVirtualRealmAddress();
        realmLeaders.AttemptID = bestServer->ID;
        realmLeaders.CompletionTime = bestServer->RecordTime;
        realmLeaders.CompletionDate = bestServer->Date;
        realmLeaders.MedalEarned = bestServer->ChallengeLevel;

        for (auto const& v : bestServer->member)
        {
            WorldPackets::ChallengeMode::ModeAttempt::Member memberData;
            memberData.VirtualRealmAddress = GetVirtualRealmAddress();
            memberData.NativeRealmAddress = GetVirtualRealmAddress();
            memberData.Guid = v.guid;
            memberData.SpecializationID = v.specId;
            realmLeaders.Members.emplace_back(memberData);
        }
        result.RealmLeaders.push_back(realmLeaders);
    }

    SendPacket(result.Write());
}

//void WorldSession::HandleGetChallengeModeRewards(WorldPackets::ChallengeMode::Misc& /*packet*/)
//{
//   // WorldPackets::ChallengeMode::Rewards rewards;
//    //SendPacket(rewards.Write());
//}
//
void WorldSession::HandleMythicPlusRequestMapStats(WorldPackets::ChallengeMode::Misc& /*packet*/)
{
    WorldPackets::ChallengeMode::MythicPlusAllMapStats stats;
    if (ChallengeByMap* last = sChallengeModeMgr->LastForMember(_player->GetGUID()))
    {
        for (auto const& v : *last)
        {
            WorldPackets::ChallengeMode::ChallengeModeMap modeMap;
            modeMap.ChallengeID = v.second->ChallengeID;
            modeMap.BestMedalDate = v.second->Date;
            modeMap.MapId = v.second->MapID;
            modeMap.CompletedChallengeLevel = v.second->ChallengeLevel;

            modeMap.LastCompletionMilliseconds = v.second->RecordTime;
            if (ChallengeData* _lastData = sChallengeModeMgr->BestForMemberMap(_player->GetGUID(), v.second->ChallengeID))
                modeMap.BestCompletionMilliseconds = _lastData->RecordTime;
            else
                modeMap.BestCompletionMilliseconds = v.second->RecordTime;

            modeMap.Affixes = v.second->Affixes;

            for (auto const& z : v.second->member)
                modeMap.BestSpecID.push_back(z.specId);

            stats.ChallengeModeMaps.push_back(modeMap);
        }
    }

    SendPacket(stats.Write());
}

void WorldSession::HandleStartChallengeMode(WorldPackets::ChallengeMode::StartChallengeMode& packet)
{
    if (packet.GobGUID.GetEntry() != ChallengeModeOrb /*|| !sWorld->getBoolConfig(CONFIG_CHALLENGE_ENABLED)*/)
        return;

    if (Item* item = _player->GetItemByEntry(138019))
    {
        InstanceMap* inst = _player->GetMap()->ToInstanceMap();
        if (!inst)
        {
            ChatHandler(_player->GetSession()).PSendSysMessage("Error: Is not a Instance Map.");
            return;
        }

        if (inst->GetSpawnMode() == DIFFICULTY_MYTHIC_KEYSTONE)
        {
            ChatHandler(_player->GetSession()).PSendSysMessage("Error: For run Mythic please rerun instance.");
            return;
        }

        if (_player->m_challengeKeyInfo.InstanceID)
        {
            ChatHandler(_player->GetSession()).PSendSysMessage("Error: Key allready run in other instance.");
            return;
        }

        if (_player->m_challengeKeyInfo.Level < 2)
        {
            _player->ChallengeKeyCharded(nullptr, _player->m_challengeKeyInfo.Level); // Deleted bugged key
            ChatHandler(_player->GetSession()).PSendSysMessage("Error: Key is bugged.");
            return;
        }

        float x = 0.0f; float y = 0.0f; float z = 0.0f; float o = 0.0f;
        if (!sChallengeModeMgr->GetStartPosition(_player->GetMapId(), x, y, z, o, _player->GetGUID()))
        {
            ChatHandler(_player->GetSession()).PSendSysMessage("Error: Start position not found.");
            return;
        }

        if (!_player->IsAlive())
        {
            ChatHandler(_player->GetSession()).PSendSysMessage("Error: Player not found or die.");
            return;
        }

        if (_player->IsInCombat())
        {
            ChatHandler(_player->GetSession()).PSendSysMessage("Error: Player in combat.");
            return;
        }

        if (Group* group = _player->GetGroup())
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* player = itr->GetSource();
                if (!player || !player->IsAlive())
                {
                    ChatHandler(_player->GetSession()).PSendSysMessage("Error: Player not found or die.");
                    return;
                }

                if (player->IsInCombat())
                {
                    ChatHandler(_player->GetSession()).PSendSysMessage("Error: Player in combat.");
                    return;
                }

                if (!player->GetMap() || player->GetMap()->ToInstanceMap() != inst)
                {
                    ChatHandler(_player->GetSession()).PSendSysMessage("Error: Player in group not this map.");
                    return;
                }
            }

            group->m_challengeEntry = sMapChallengeModeStore.LookupEntry(_player->m_challengeKeyInfo.ID);
            group->m_affixes.fill(0);

            MapChallengeModeEntry const* challengeEntry = sDB2Manager.GetChallengeModeByMapID(_player->GetMapId());
            if (!group->m_challengeEntry || !challengeEntry || challengeEntry->MapID != group->m_challengeEntry->MapID)
            {
                group->m_challengeEntry = nullptr;
                ChatHandler(_player->GetSession()).PSendSysMessage("Error: Is not this challenge.");
                return;
            }

            group->m_challengeOwner = _player->GetGUID();
            group->m_challengeItem = item->GetGUID();
            group->m_challengeLevel = _player->m_challengeKeyInfo.Level;

            if (group->m_challengeLevel > 3)
                group->m_affixes[0] = _player->m_challengeKeyInfo.Affix;
            if (group->m_challengeLevel > 6)
                group->m_affixes[1] = _player->m_challengeKeyInfo.Affix1;
            if (group->m_challengeLevel > 9)
                group->m_affixes[2] = _player->m_challengeKeyInfo.Affix2;

            WorldPackets::ChallengeMode::ChangePlayerDifficultyResult result;
            result.Result = AsUnderlyingType(ChangeDifficultyResult::DIFFICULTY_CHANGE_SET_COOLDOWN_S);
            result.CooldownReason = 2813862382;
            group->BroadcastPacket(result.Write(), true);

            WorldPackets::ChallengeMode::ChangePlayerDifficultyResult result2;
            result2.Result = AsUnderlyingType(ChangeDifficultyResult::DIFFICULTY_CHANGE_BY_PARTY_LEADER);
            result2.InstanceMapID = _player->GetMapId();
            result2.DifficultyRecID = DIFFICULTY_MYTHIC_KEYSTONE;

            group->SetDungeonDifficultyID(DIFFICULTY_MYTHIC_KEYSTONE);

            for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                if (Player* player = itr->GetSource())
                {
                    player->SetDungeonDifficultyID(DIFFICULTY_MYTHIC_KEYSTONE);
                    player->SendDirectMessage(result2.Write());
                    player->TeleportToChallenge(_player->GetMapId(), x, y, z, o);
                    player->CastSpell(player, ChallengersBurden, true);
                }
            }
            if (GameObject* challengeOrb = ObjectAccessor::FindGameObject(packet.GobGUID))
            {
                challengeOrb->SetGoState(GO_STATE_ACTIVE);
                challengeOrb->AddFlag(GO_FLAG_NODESPAWN);
            }
        }
        else
        {
            _player->m_challengeKeyInfo.challengeEntry = sMapChallengeModeStore.LookupEntry(_player->m_challengeKeyInfo.ID);

            MapChallengeModeEntry const* challengeEntry = sDB2Manager.GetChallengeModeByMapID(_player->GetMapId());
            if (!_player->m_challengeKeyInfo.challengeEntry || !challengeEntry || challengeEntry->MapID != _player->m_challengeKeyInfo.challengeEntry->MapID)
            {
                _player->m_challengeKeyInfo.challengeEntry = nullptr;
                ChatHandler(_player->GetSession()).PSendSysMessage("Error: Is not this challenge.");
                return;
            }

            WorldPackets::ChallengeMode::ChangePlayerDifficultyResult result;
            result.Result = AsUnderlyingType(ChangeDifficultyResult::DIFFICULTY_CHANGE_SET_COOLDOWN_S);
            result.CooldownReason = 2813862382;
            SendPacket(result.Write(), true);

            WorldPackets::ChallengeMode::ChangePlayerDifficultyResult result2;
            result2.Result = AsUnderlyingType(ChangeDifficultyResult::DIFFICULTY_CHANGE_BY_PARTY_LEADER);
            result2.InstanceMapID = _player->GetMapId();
            result2.DifficultyRecID = DIFFICULTY_MYTHIC_KEYSTONE;

            _player->SetDungeonDifficultyID(DIFFICULTY_MYTHIC_KEYSTONE);
            SendPacket(result2.Write());
            _player->TeleportToChallenge(_player->GetMapId(), x, y, z, o);
            _player->CastSpell(_player, ChallengeSpells::ChallengersBurden, true);

            if (GameObject* challengeOrb = ObjectAccessor::FindGameObject(packet.GobGUID))
            {
                challengeOrb->SetGoState(GOState::GO_STATE_ACTIVE);
                challengeOrb->AddFlag(GO_FLAG_NODESPAWN);
            }
        }
    }
}

void WorldSession::SendChallengeModeMapStatsUpdate(uint32 keyID)
{
    WorldPacket packet(6 * 4);

    for (auto l_ChallengeData : _player->m_CompletedChallenges)
    {
        if (l_ChallengeData.first == keyID)
        {
            CompletedChallenge l_CompletedChallenge = l_ChallengeData.second;

            packet << uint32(l_CompletedChallenge.MapID);
            packet << uint32(l_ChallengeData.first);
            packet << uint32(l_CompletedChallenge.BestCompletion);
            packet << uint32(l_CompletedChallenge.LastCompletion);
            packet << uint32(l_CompletedChallenge.BestMedal);
            packet << uint32(l_CompletedChallenge.BestMedalDate);

            uint32 l_SpecCount = 5;
            packet << uint32(l_SpecCount);

            for (uint32 I = 0; I < 3; ++I)
                packet << uint32(0);

            for (uint32 J = 0; J < l_SpecCount; ++J)
                packet << uint16(0);    ///pecID
        }
    }

    SendPacket(&packet);
}

void WorldSession::HandleResetChallengeModeCheat(WorldPackets::ChallengeMode::ResetChallengeMode& /*packet*/)
{
}

