#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "QuestDef.h"
#include "Player.h"
#include <Globals/ObjectMgr.h>

enum Callboards
{
    GO_ALLIANCE_CALLBOARD = 278574,
    SPELL_ALLIANCE_WARBOARD = 261654,
    PLAYERCHOICE_ALLIANCE = 352,

    GO_HORDE_CALLBOARD = 0,
    PLAYERCHOICE_HORDE = 261655,
};

//278574
struct go_callboard : public GameObjectAI
{
    go_callboard(GameObject* go) : GameObjectAI(go) { }
    
    bool GossipHello(Player* player) override
    {
        if (player->GetTeam() == ALLIANCE)
        {
            player->SendPlayerChoice(player->GetGUID(), 352);
        }
        return true;
    }
};

class playerchoice_callboard : public PlayerScript
{
public:
    playerchoice_callboard() : PlayerScript("playerchoice_callboard") { }
    
    void OnPlayerChoiceResponse(Player* player, uint32 choiceId, uint32 responseId) override
    {
        
        switch (responseId)
        {
            /*case 847: GetQuestForPlayer(this, 28496); break; // Azshara
            case 848: GetQuestForPlayer(this, 28494); break; // Northern Barrens
            case 864: GetQuestForPlayer(this, 28568); break; // Silverpine Forest
            case 851: GetQuestForPlayer(this, 28493); break; // Ashenvale
            case 868: GetQuestForPlayer(this, 28571); break; // Hillsbrad Foothills
            case 872: GetQuestForPlayer(this, 28688); break; // Northern Stranglethorn
            case 852: GetQuestForPlayer(this, 28532); break; // Stonetalon Mountains
            case 854: GetQuestForPlayer(this, 28548); break; // Desolace
            case 853: GetQuestForPlayer(this, 28549); break; // Southern Barrens
            case 856: GetQuestForPlayer(this, 28510); break; // Feralas
            case 855: GetQuestForPlayer(this, 28504); break; // Thousand Needles
            case 858: GetQuestForPlayer(this, 28509); break; // Tanaris
            case 861: GetQuestForPlayer(this, 28526); break; // Un'Goro Crater
            case 860: GetQuestForPlayer(this, 28545); break; // Winterspring
            case 862: GetQuestForPlayer(this, 28527); break; // Silithus
            case 887: GetQuestForPlayer(this, 28711); break; // Borean Tundra
            case 888: GetQuestForPlayer(this, 49533); break; // Howling Fjord*/
        case 2262: player->GetQuestForPlayer(player, 28492); break; // Ashenwale 28492
        case 2254: player->GetQuestForPlayer(player, 28551); break; // Southern Barrens
        case 2239: player->GetQuestForPlayer(player, 28562); break; // Westfall
        case 2245: player->GetQuestForPlayer(player, 28563); break; // Redrige Mountains
        case 2236: player->GetQuestForPlayer(player, 28564); break; // Duskwood
        case 2224: player->GetQuestForPlayer(player, 28702); break; // The Cape of Stranglethorn
        case 3: player->GetQuestForPlayer(player, 28578); break; // Eastern Plaguelands
        case 2218: player->GetQuestForPlayer(player, 28708); break; // Hellfire Peninsula
        case 12: player->GetQuestForPlayer(player, 28673); break; // Blasted Lands
        case 2212: player->GetQuestForPlayer(player, 28709); break; // Borean Tundra
        case 4: player->GetQuestForPlayer(player, 49557); break; // Valley of the four winds
        case 10:player->GetQuestForPlayer(player, 49558); break; // Krasarang Wilds
        case 1: player->GetQuestForPlayer(player, 49564); break; // Gorgrond
        case 2209: player->GetQuestForPlayer(player, 34398); break; // Tanaan Jungle
        default:
            break;
        }
    }
};
void AddSC_call_boards_scripts()
{
    RegisterGameObjectAI(go_callboard);
    new (playerchoice_callboard);
}
