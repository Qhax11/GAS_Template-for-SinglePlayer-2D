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
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Attack_Event, "Gameplay.Attack.Event");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_DamageImmune, "Gameplay.DamageImmune");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Event_TakeDamage, "Gameplay.Event.TakeDamage");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Event_Death, "Gameplay.Event.Death");
	
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_State_Debuff, "Gameplay.State.Debuff");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_State_Debuff_Stun, "Gameplay.State.Debuff.Stun");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_State_Debuff_Slow, "Gameplay.State.Debuff.Slow");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_State_Dead, "Gameplay.State.Dead");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_State_InCombat, "Gameplay.State.InCombat");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EffectData_SetByCaller_DamageAmount, "Gameplay.EffectData.SetByCaller.DamageAmount");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EffectData_SetByCaller_GainHealthAmount, "Gameplay.EffectData.SetByCaller.GainHealthAmount");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EffectData_SetByCaller_GainManaAmount, "Gameplay.EffectData.SetByCaller.GainManaAmount");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EffectData_EnableLifeSteal, "Gameplay.EffectData.EnableLifeSteal");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_EffectData_EnableCriticalDamage, "Gameplay.EffectData.EnableCriticalDamage");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Entity_Hero, "Gameplay.Entity.Hero");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_Entity_Enemy, "Gameplay.Entity.Enemy");

	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_HeroAbility0, "Gameplay.Hero.Ability0");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_HeroAbility1, "Gameplay.Hero.Ability1");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_HeroAbility2, "Gameplay.Hero.Ability2");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Gameplay_HeroAbility3, "Gameplay.Hero.Ability3");

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

	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_AttachedEffectText_PhysicalDamage, "GameplayCue.AttachedEffectText.PhysicalDamage");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_AttachedEffectText_CriticalDamage, "GameplayCue.AttachedEffectText.CriticalDamage");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_AttachedEffectText_Bleed, "GameplayCue.AttachedEffectText.Bleed");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_AttachedEffectText_GainHealth, "GameplayCue.AttachedEffectText.GainHealth");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_AttachedEffectText_GainMana, "GameplayCue.AttachedEffectText.GainMana");

	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_HeroMessageHUD_LevelUp, "GameplayCue.HeroMessageHUD.LevelUp");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_HeroMessageHUD_Died, "GameplayCue.HeroMessageHUD.Died");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_HeroMessageHUD_Stunned, "GameplayCue.HeroMessageHUD.Stunned");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_HeroMessageHUD_Slowed, "GameplayCue.HeroMessageHUD.Slowed");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_HeroMessageHUD_GainPhysicalArmor, "GameplayCue.HeroMessageHUD.GainPhysicalArmor");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_HeroMessageHUD_GainLifeSteal, "GameplayCue.HeroMessageHUD.GainLifeSteal");

	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_VFX_Blood, "GameplayCue.VFX.Blood");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_VFX_Heal, "GameplayCue.VFX.Heal");
	
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Sound, "GameplayCue.Sound");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Sound_TakeDamage, "GameplayCue.Sound.TakeDamage");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Sound_AttackSwing, "GameplayCue.Sound.AttackSwing");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Sound_Death, "GameplayCue.Sound.Death");
	UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Sound_LevelUp, "GameplayCue.Sound.LevelUp");

	/************************************************
	*-------------------<AI Tags>-------------------*
	* Add all of the AI related tags to here.       *
	*************************************************/

	UE_DEFINE_GAMEPLAY_TAG(TAG_AI, "AI");

	/************************************************
	*-------------------<UI Tags>-------------------*
	* Add all of the UI related tags to here.       *
	*************************************************/

	UE_DEFINE_GAMEPLAY_TAG(TAG_UI, "UI");

	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_HitTypeText_Critical, "UI.HitTypeText.Critical");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_HitTypeText_Blind, "UI.HitTypeText.Blind");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_HitTypeText_Physical, "UI.HitTypeText.Physical");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_HitTypeText_Magical, "UI.HitTypeText.Magical");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_HitTypeText_Healing, "UI.HitTypeText.Heal");

	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_Cooldown_Ability0, "UI.Cooldown.Ability0");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_Cooldown_Ability1, "UI.Cooldown.Ability1");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_Cooldown_Ability2, "UI.Cooldown.Ability2");
	UE_DEFINE_GAMEPLAY_TAG(TAG_UI_Cooldown_Ability3, "UI.Cooldown.Ability3");
}