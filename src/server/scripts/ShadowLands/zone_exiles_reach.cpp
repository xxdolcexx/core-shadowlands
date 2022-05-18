#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "PhasingHandler.h"
#include "Log.h"
#include "Chat.h"
#include "Transport.h"
#include "ObjectAccessor.h"
#include <Maps/MapManager.h>

enum ExilesReachQuests
{
    QUEST_WARMING_UP = 56775,
    QUEST_STAND_YOUR_GROUND = 58209,
    QUEST_BRACE_FOR_IMPACT = 58208,
    QUEST_MURLOC_MANIA = 55122,
    QUEST_EMERGENCY_FIRST_AID = 54951,
    QUEST_FINDING_THE_LOST_EXPEDITION = 54952,
    QUEST_COOKING_MEAT = 55174,
    QUEST_ENHANCED_COMBAT_TACTICS = 59254,
    QUEST_NORTHBOUND = 55173,
    QUEST_DOWN_WITH_THE_QUILBOAR = 55186,
    QUEST_FORBIDDEN_QUILBOAR_NECROMANCY = 55184,
    QUEST_THE_SCOUT_O_MATIC_5000 = 55193,
    QUEST_RE_SIZING_THE_SITUATION = 56034,
    QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR = 55879,
    QUEST_THE_HARPY_PROBLEM = 55196,
    QUEST_THE_RESCUE_OF_MEREDY_HUNTSWELL = 55763,
    QUEST_HARPY_CULLING = 55764,
    QUEST_PURGE_THE_TOTEMS = 55881,
    QUEST_MESSAGE_TO_BASE = 55882,
    QUEST_WESTWARD_BOUND = 55965,
    QUEST_WHO_LURKS_IN_THE_PIT = 55639,
    QUEST_TO_DARKMAUL_CITADEL = 56344,
    QUEST_RIGHT_BENEATH_THEIR_EYES = 55981,
    QUEST_LIKE_OGRES_TO_THE_SLAUGHTER = 55988,
    QUEST_CATAPULT_DESTRUCTION = 55989,
    QUEST_CONTROLLING_THEIR_STONES = 55990,
    QUEST_DUNGEON_DARKMAUL_CITADEL = 55992,
    QUEST_AN_END_TO_BEGINNINGS = 55991,

    QUEST_H_WARMING_UP = 59926,
    QUEST_H_STAND_YOUR_GROUND = 59927,
    QUEST_H_BRACE_FOR_IMPACT = 59928,
    QUEST_H_MURLOCK_MANIA = 59929,
    QUEST_H_EMERGENCY_FIRST_AID = 59930,
    QUEST_H_FINDING_THE_LOST_EXPEDITION = 59931,
    QUEST_H_COOKING_MEAT = 59932,
    QUEST_H_ENHANCED_COMBAT_TACTICS = 59933,
    QUEST_H_NORTHBOUND = 59935,
    QUEST_H_DOWN_WITH_THE_QUILBOAR = 59938,
    QUEST_H_FORBIDDEN_QUILBOAR_NECROMANCY = 59939,
    QUEST_H_THE_CHOPPY_BOOSTER_MK5 = 59940,
    QUEST_H_RESIZING_THE_SITUATION = 59941,
    QUEST_H_THE_REDEATHER = 59942,
    QUEST_H_THE_HARPY_PROBLEM = 59943,
    QUEST_H_THE_RESCUE_OF_HERBERT_GLOOMBURST = 59944,
    QUEST_H_HARPY_CULLING = 59945,
    QUEST_H_PURGE_THE_TOTEMS = 59946,
    QUEST_H_MESSAGE_TO_BASE = 59947,
    QUEST_H_WESTWARD_BOUND = 59948,
    QUEST_H_WHO_LUKS_IN_THE_PIT = 59949,
    QUEST_H_STOCKING_UP_ON_SUPPLIES = 59950,
    QUEST_H_TO_DARKMAUL_CITADEL = 59975,
};
enum PhasesOnArea
{
    // Horde_Phase
    HORDE_PHASE_2 = 12950,
    HORDE_PHASE_1 = 12930,
    HORDE_PHASE_6 = 12990,


    PHASE_GENERIC = 12940,         // generic phase, active always
    PHASE_GENERIC_Z = 16752,       // generic phase for zombies etc. removed on chapter 7
};

enum Scenes
{
    SCENE_ALI_HORDE_CRASHED_ON_ISLAND = 2708,
    SCENE_HENRY_REUNION = 2717,
    SCENE_GRIMAXE_REUNION = 2905,
    SCENE_GORGROTHS_RITUAL = 2820,
    SCENE_SKELETON_ARMY_DARKMAUL_PLAINS = 2712,
    SCENE_FLY_AWAY = 2908,
};

enum ExilesReachArea
{
    AREA_NORTH_SEA = 10639,
};

enum MapsID
{
    EXILESREACH_MAP = 2175
};
enum transport
{
    SHIP_TRANSPORT_ALLIANCE = 333479
};

enum CaptainGarricTxt
{
    NPC_GARRIC = 156280,            //creatureId

    GARRIC_TXT0 = 0,                //cTextGuid
    GARRIC_TXT1 = 1,
    GARRIC_TXT2 = 2,
    GARRIC_TXT3 = 3,
    GARRIC_TXT4 = 4,

};

class exiles_reach : public PlayerScript
{
public:
    exiles_reach() : PlayerScript("exiles_reach") { }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        // Set zone as sanctuary
        if (player->GetMapId() == EXILESREACH_MAP)
            player->AddPvpFlag(UNIT_BYTE2_FLAG_SANCTUARY);

        if (player->GetMapId() == EXILESREACH_MAP && player->GetTeam() == ALLIANCE)
        {
            
            player->GetPhaseShift(), 15284;
            
            
        }
        else if (player->GetMapId() == EXILESREACH_MAP && player->GetTeam() == HORDE)
        {
            
        }
    }

    void OnUpdateArea(Player* player, uint32 newArea, uint32 /*oldArea*/)
    {
        // Set zone as sanctuary
        if (player->GetMapId() == EXILESREACH_MAP)
            player->AddPvpFlag(UNIT_BYTE2_FLAG_SANCTUARY);

        switch (newArea = player->GetAreaId())
        {
        case AREA_NORTH_SEA:
            if (Creature* npc = player->FindNearestCreature(NPC_GARRIC, 20.0f, true))
            {
                player->GetScheduler().Schedule(Milliseconds(5000), [npc, player](TaskContext context)
                {
                    npc->AI()->Talk(GARRIC_TXT0, player);
                });
            }
            break;
        default:
            break;
        }

        //OnCheckPhase(player); need fix it
    }

    void OnPlayerExit(Player* player)
    {
        // Remove sanctuary flag when leaving exiles reach
        player->RemovePvpFlag(UNIT_BYTE2_FLAG_SANCTUARY);
    }
};

void OnCheckPhase(Player* player)
{
    if ((player->GetMapId() == EXILESREACH_MAP) && (player->GetZoneId() == 10424))
    {
        if ((player->GetQuestStatus(QUEST_BRACE_FOR_IMPACT) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_BRACE_FOR_IMPACT) == QUEST_STATUS_REWARDED))
        {
            PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
            PhasingHandler::AddPhase(player, PHASE_GENERIC_Z, true);
        }

        if ((player->GetQuestStatus(QUEST_BRACE_FOR_IMPACT) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_BRACE_FOR_IMPACT) == QUEST_STATUS_REWARDED))
        {
            PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
            PhasingHandler::AddPhase(player, PHASE_GENERIC_Z, true);

        }

        if ((player->GetQuestStatus(QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR) == QUEST_STATUS_REWARDED) || (player->GetQuestStatus(QUEST_H_THE_REDEATHER) == QUEST_STATUS_REWARDED))
        {
            PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
        }
    }
};

//160737 npc_combat_dummy
struct npc_combat_dummy : public ScriptedAI
{
    npc_combat_dummy(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->ToPlayer())
            player->KilledMonsterCredit(174954);

        me->setDeathState(JUST_DIED);
    }
};

void AddSC_zone_exiles_reach()
{
 
}
