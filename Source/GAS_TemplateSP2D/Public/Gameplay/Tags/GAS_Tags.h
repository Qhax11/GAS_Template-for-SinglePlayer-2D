// Qhax's GAS Template for SinglePlayer

#pragma once

#include "NativeGameplayTags.h"


namespace GAS_Tags
{
	/************************************************
	*----------------<Gameplay Tags>----------------*
	* Add all of the Gameplay related tags to here. *
	*************************************************/

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Health);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Health_Full);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Health_Regen);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Mana);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Mana_Full);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Mana_Regen);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Attack);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Attack_Cost);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Attack_Cooldown);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Attack_Event);
	
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_State_Debuff);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_State_Debuff_Stun);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_EntityHero);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_EntityShades);
	
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_HeroAbility0);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_HeroAbility1);
	
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI_Cooldown_Skill_Ability0);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI_Cooldown_Skill_Ability1);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_SetByCallerHealingAmount);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_EffectData_EnableLifeSteal);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_EffectData_EnableSelfHeal);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_EffectData_EnableCriticalDamage);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_EffectData_OverrideShowText);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_GameplayEvent_TakeDamage);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_GameplayEvent_Death);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_State_Dead);


	/**********************************************
	*----------------<Filter Tags>----------------*
	* Add all of the Filter related tags to here. *
	***********************************************/

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Filter);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Filter_Team);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Filter_Team_Hostile);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Filter_Team_Friend);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Filter_Team_Neutral);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_SetByCaller_DamageAmount);


	/***************************************************
	*----------------<GameplayCue Tags>----------------*
	* Add all of the GameplayCue related tags to here. *
	****************************************************/

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayCue_ShowText_Damage);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayCue_ShowText_Blood);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayCue_ShowText_Healing);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayCue_ShowText_Critical);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayCue_Sound);
	
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_InCombat);

	/************************************************
	*-------------------<AI Tags>-------------------*
	* Add all of the AI related tags to here.       *
	*************************************************/

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_AI);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_AI_Logic_AttackToAttackingHero);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_AI_Logic_AttackToTargetHero);
	

	/************************************************
	*-------------------<UI Tags>-------------------*
	* Add all of the UI related tags to here.       *
	*************************************************/
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI_HitTypeText_Critical);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI_HitTypeText_Blind);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI_HitTypeText_Physical);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI_HitTypeText_Magical);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI_HitTypeText_Healing);

	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI_GameplaycueShowInfoOnHUD);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI_GameplaycueShowInfoOnHUD_Gold);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI_GameplaycueShowInfoOnHUD_XP);
	GAS_TEMPLATESP2D_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_UI_GameplaycueShowInfoOnHUD_LevelUp);

}