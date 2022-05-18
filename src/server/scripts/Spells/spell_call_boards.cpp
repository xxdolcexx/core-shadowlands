#include "ScriptMgr.h"
#include "CellImpl.h"
#include "CreatureAIImpl.h"
#include "GridNotifiersImpl.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "World.h"
#include <Server/Packets/QuestPackets.h>

enum SpellChoiceBoards
{
    HEROS_CALL_BOARD    = 261654,
    WAR_BOARD_HORDE     = 261655
};


class spell_call_board : public SpellScriptLoader
{
public:
    spell_call_board() : SpellScriptLoader("spell_call_board") { }
    class spell_call_board_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_call_board_SpellScript);
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(spells);
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetCaster(), spells[urand(0, 3)], true);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_call_board_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }

        SpellScript* GetSpellScript()
        {
            return new spell_call_board_SpellScript();
        }
       
    private:
        static uint32 const spells[2];
    };
};
uint32 const spell_call_board::spell_call_board_SpellScript::spells[2] =
{
    HEROS_CALL_BOARD,
    WAR_BOARD_HORDE
};

void AddSC_call_boards_spell_scripts()
{
    new spell_call_board();
}
