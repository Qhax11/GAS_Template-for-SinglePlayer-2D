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

	UE_DEFINE_GAMEPLAY_TAG(TAG_State_Debuff, "State.Debuff");
	UE_DEFINE_GAMEPLAY_TAG(TAG_State_Debuff_Stun, "State.Debuff.Stun");


	// Secntion name should be in here.

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EntityHero, "Entity.Hero");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EntityShades, "Entity.Shades");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_HeroAbility0, "Hero.Ability0");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_HeroAbility1, "Hero.Ability1");
	
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_Cooldown_Skill_Ability0, "Cooldown.Skill.Ability0");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_Cooldown_Skill_Ability1, "Cooldown.Skill.Ability1");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_SetByCallerHealingAmount, "EffectData.SetByCaller.HealingAmount");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EnableLifeSteal, "EffectData.EnableLifeSteal");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EnableSelfHeal, "EffectData.EnableSelfHeal");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EnableCriticalDamage, "EffectData.EnableCriticalDamage");


	/**********************************************
	*----------------<Filter Tags>----------------*
	* Add all of the Filter related tags to here. *
	***********************************************/

	UE_DEFINE_GAMEPLAY_TAG(TAG_Filter, "Filter");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Filter_Team, "Filter.Team");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Filter_Team_Friend, "Filter.Team.Friend");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Filter_Team_Hostile, "Filter.Team.Hostile");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Filter_Team_Neutral, "Filter.Team.Neutral");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_GameplayEvent_TakeHeal, "GameplayEvent.TakeHeal");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_GameplayEvent_DealHeal, "GameplayEvent.DealHeal");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_GameplayEvent_TakeDamage_Health, "GameplayEvent.TakeDamage.Health");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_GameplayEvent_TakeDamage_Shield, "GameplayEvent.TakeDamage.Shield");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_GameplayEvent_DealDamage_Health, "GameplayEvent.DealDamage.Health");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_GameplayEvent_DealDamage_Shield, "GameplayEvent.DealDamage.Shield");


	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_GameplayEventDeath, "GameplayEvent.Death");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_State_Dead, "State.Dead");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_InCombat, "Gameplay.InCombat");

	/***************************************************
	*----------------<GameplayCue Tags>----------------*
	* Add all of the GameplayCue related tags to here. *
	****************************************************/

	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_LockCamera, "GameplayCue.LockCamera");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_UnlockCamera, "GameplayCue.UnlockCamera");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_ShowText_Damage, "GameplayCue.ShowText.Damage");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Effect_Blood, "GameplayCue.Effect.Blood");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_ShowText_Blood, "GameplayCue.ShowText.Blood");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Effect_Healing, "GameplayCue.Effect.Healing");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_ShowText_Healing, "GameplayCue.ShowText.Healing");

	/* These tags are for reaching data  */
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Sound, "Gameplay.Sound");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Sound_Jump, "Gameplay.Sound.Jump");

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