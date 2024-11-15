// Qhax's GAS Template for SinglePlayer

#include "Gameplay/Tags/GAS_Tags.h"

namespace GAS_Tags
{
	/************************************************
	*----------------<Gameplay Tags>----------------*
	* Add all of the Gameplay related tags to here. *
	*************************************************/

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay, "Gameplay");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Health, "Gameplay.Health");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Health_Full, "Gameplay.Health.Full");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Health_Regen, "Gameplay.Health.Regen");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Mana, "Gameplay.Mana");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Mana_Full, "Gameplay.Mana.Full");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Mana_Regen, "Gameplay.Mana.Regen");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Attack, "Gameplay.Attack");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Attack_Cost, "Gameplay.Attack.Cost");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Attack_Cooldown, "Gameplay.Attack.Cooldown");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Attack_Event, "Gameplay.Attack.Event");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_DamageImmune, "Gameplay.DamageImmune");

	UE_DEFINE_GAMEPLAY_TAG(TAG_State_Debuff, "State.Debuff");
	UE_DEFINE_GAMEPLAY_TAG(TAG_State_Debuff_Stun, "State.Debuff.Stun");

	// Section name should be in here.

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Entity_Hero, "Entity.Hero");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Entity_Enemy, "Entity.Enemy");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_HeroAbility0, "Hero.Ability0");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_HeroAbility1, "Hero.Ability1");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_HeroAbility2, "Hero.Ability2");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_HeroAbility3, "Hero.Ability3");
	
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EffectData_SetByCaller_DamageAmount, "Gameplay.EffectData.SetByCaller.DamageAmount");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EffectData_SetByCaller_HealingAmount, "Gameplay.EffectData.SetByCaller.HealingAmount");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EffectData_EnableLifeSteal, "Gameplay.EffectData.EnableLifeSteal");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EffectData_EnableSelfHeal, "Gameplay.EffectData.EnableSelfHeal");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EffectData_EnableCriticalDamage, "Gameplay.EffectData.EnableCriticalDamage");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Event_TakeDamage, "Gameplay.Event.TakeDamage");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Event_Death, "Gameplay.Event.Death");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_State_Dead, "Gameplay.State.Dead");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_State_InCombat, "Gameplay.State.InCombat");

	/**********************************************
	*----------------<Filter Tags>----------------*
	* Add all of the Filter related tags to here. *
	***********************************************/

	UE_DEFINE_GAMEPLAY_TAG(TAG_Filter, "Filter");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Filter_Team, "Filter.Team");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Filter_Team_Friend, "Filter.Team.Friend");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Filter_Team_Hostile, "Filter.Team.Hostile");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Filter_Team_Neutral, "Filter.Team.Neutral");

	/***************************************************
	*----------------<GameplayCue Tags>----------------*
	* Add all of the GameplayCue related tags to here. *
	****************************************************/

	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_ShowText_Damage, "GameplayCue.ShowText.Damage");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_ShowText_Blood, "GameplayCue.ShowText.Blood");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_ShowText_Healing, "GameplayCue.ShowText.Healing");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_ShowText_Critical, "GameplayCue.ShowText.Critical");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_ShowText_Mana, "GameplayCue.ShowText.Mana");

	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Effect_Blood, "GameplayCue.Effect.Blood");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Effect_Healing, "GameplayCue.Effect.Healing");
	
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Sound, "GameplayCue.Sound");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Sound_Jump, "GameplayCue.Sound.Jump");

	/************************************************
	*-------------------<AI Tags>-------------------*
	* Add all of the AI related tags to here.       *
	*************************************************/

	UE_DEFINE_GAMEPLAY_TAG(TAG_AI, "AI");
	UE_DEFINE_GAMEPLAY_TAG(TAG_AI_Logic_AttackToAttackingHero, "AI.Logic.AttackToAttackingHero");
	UE_DEFINE_GAMEPLAY_TAG(TAG_AI_Logic_AttackToTargetHero, "AI.Logic.AttackToTargetHero");

	/************************************************
	*-------------------<UI Tags>-------------------*
	* Add all of the UI related tags to here.       *
	*************************************************/

	UE_DEFINE_GAMEPLAY_TAG(TAG_UI, "UI");

	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_HitTypeText_Critical, "UI.HitTypeText.Critical");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_HitTypeText_Blind, "UI.HitTypeText.Blind");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_HitTypeText_Physical, "UI.HitTypeText.Physical");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_HitTypeText_Magical, "UI.HitTypeText.Magical");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_HitTypeText_Healing, "UI.HitTypeText.Healing");

	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_Cooldown_Ability0, "UI.Cooldown.Ability0");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_Cooldown_Ability1, "UI.Cooldown.Ability1");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_Cooldown_Ability2, "UI.Cooldown.Ability2");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_Cooldown_Ability3, "UI.Cooldown.Ability3");

	/* TODO: Tags below are incorrect they If These tags being used for GameplayCues,
	 * These tags should be under GameplayCue, You can make a them more specific by
	 * Adding UI tag after GameplayCue, Like: (GameplayCue_UI -> GameplayCue.UI).
	 * But if only getting used by UI then these tags should be under UI.
	 */
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_GameplaycueShowInfoOnHUD, "Gameplaycue.UI.ShowInfoOnHUD");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_GameplaycueShowInfoOnHUD_Gold, "Gameplaycue.UI.ShowInfoOnHUD.Gold");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_GameplaycueShowInfoOnHUD_XP, "Gameplaycue.UI.ShowInfoOnHUD.XP");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_GameplaycueShowInfoOnHUD_LevelUp, "Gameplaycue.UI.ShowInfoOnHUD.LevelUp");

}