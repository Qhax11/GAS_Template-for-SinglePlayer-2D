
## Introduction
The template project was developed in version 5.4.

This project provides the foundational systems for a single-player, action-based game, using the Gameplay Ability System (GAS) for its core functionality. 

Most of the logic is written in C++, with the exception of a few UI-related blueprint elements. To fully understand and utilize the project, a basic understanding of GAS and C++ is required.

Designed with modularity and clean code principles in mind, this template offers a robust architecture that simplifies the integration of complex systems while maintaining scalability for future development. 

It is particularly suitable for action-adventure, hack-and-slash, Souls-like, and roguelike genres, providing a strong base for developers to build upon.

This is the gameplay test video. Sorry for the low quality, you can check it out using this link: https://www.youtube.com/watch?v=71bsDGZbWys&ab_channel=%C5%9Eamil%C3%96zel

https://github.com/user-attachments/assets/6ad81453-153e-4db1-8799-18257d7ed7d8

## Contents
- [Ability System Management](#Ability-System-Management)
     - [Dynamic Ability Assignment](#1-Dynamic-Ability-Assignment) 
     - [Ability Level Scaling](#2-Ability-Level-Scaling)
     - [UI Integration for Abilities](#3-UI-Integration-for-Abilities)
- [Taking and Dealing Damage](#Taking-and-Dealing-Damage)
     - [Dealing Damage Logic](#1-Dealing-Damage-Logic)
     - [Take Damage Handling](#2-Take-Damage-Handling)
     - [Damage UI Feedback](#3-Damage-UI-Feedback)
- [Character Death and Respawn](#Character-Death-and-Respawn)
     - [Death Mechanic and Logic](#1-Death-Mechanic-and-Logic)
     - [Respawn Handling](#2-Respawn-Handling)
     - [UI for Death](#3-UI-for-Death)
- [Combat Buffs and Debuffs](#Combat-Buffs-and-Debuffs)
     - [Crowd Control Effects](#1-Crowd-Control-Effects)
     - [Attributes and Combat Mechanics](#2-Attributes-and-Combat-Mechanics)
- [Message System](#Message-System)
     - [Hero Message HUD](#1-Hero-Message-HUD)
     - [Attached Effect Text](#2-Attached-Effect-Text)
- [Sound System](#Sound-System)
     - [Sound Cue Execution](#1-Sound-GameplayCue)
     - [Actor-Specific Sound Data](#2-Actor-Sounds-Data)
    

## Ability System Management

### **1. Dynamic Ability Assignment**
Explains how abilities are dynamically added or removed at the beginning of the game or during gameplay, along with automatic UI updates.
- An ability data asset is used to grant abilities, attributes, and necessary effects to the ASC at the start of the game
  
![image](https://github.com/user-attachments/assets/3dde3e3a-92aa-4340-8cad-dced9957440b)

- The UAC_AbilitySet component holds this data and, through its Initialize function, calls the GiveAbility function on the Ability System Component. 

![image](https://github.com/user-attachments/assets/092820ac-60eb-462c-942e-0da93388c3b3)

- Additionally, it broadcasts that the ability set has been successfully granted, which is important for UI classes like health bars that need to listen for attribute initialization.
  
```c++
void UAC_AbilitySet::Initialize(UGAS_AbilitySystemComponent* ASC)
{
	if (!ASC)
	{
		UE_LOG(LogTemp, Warning, TEXT("ASC is null in: %s. AbilitySet cannot be initialized."), *GetName());
		return;
	}
	if (ASC->GiveAbilitySet(AbilitySet))
	{
		OnAbilitySetGiven.Broadcast(GetOwner());
	}
}
```

### **2. Ability Level Scaling**
Explains how abilities can level up, modifying attributes like cooldown, cost, and damage.

- Typically, when an ability levels up, three key attributes are affected: Cost, Cooldown, and Applied Damage. These values are pre-defined in a Curve Data Table, where they are mapped to specific levels.
  

![ScreenShot](https://github.com/user-attachments/assets/0ca4f3c8-a424-43d2-ab96-221ae97ad1d5)

- These values are linked to the corresponding gameplay effect values. For instance, the Cooldown value is tied to the Cooldown Gameplay Effect, and it pulls its value from the Curve Data Table based on the ability's level.
  
![image](https://github.com/user-attachments/assets/51099c70-d067-478f-a331-161c66c26dbf)

- The IncreaseLevel function inside the UGAS_GameplayAbilityBase accesses the ability's spec and increments its level property. Once the level is increased, the function broadcasts the updated level, cost, and cooldown values to inform other systems about these changes.

```c++
void UGAS_GameplayAbilityBase::IncreaseLevel(UAbilitySystemComponent* AbilitySystemComp)
{
	if (!AbilitySystemComp) 
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilitySystemComp is null in %s."), *GetName());
		return;
	}

	// Using the CDO here because "FindAbilitySpecFromClass" returns the CDO if called immediately after granting the ability.
	UGAS_GameplayAbilityBase* CDO_AbilityBase = Cast<UGAS_GameplayAbilityBase>(GetClass()->GetDefaultObject());
	FGameplayAbilitySpec* CDO_AbilitySpec = AbilitySystemComp->FindAbilitySpecFromClass(CDO_AbilityBase->GetClass());
	if (!CDO_AbilitySpec)
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilitySpec is null in %s."), *GetName());
		return;
	}

	int32 NewAbilityLevel = ++CDO_AbilitySpec->Level;

	// This is actual setting.
	CDO_AbilitySpec->Level = NewAbilityLevel;

	CDO_AbilityBase->OnAbilityLevelChanged.Broadcast(this, NewAbilityLevel);

	float NewCost = GetCost(NewAbilityLevel);
	CDO_AbilityBase->OnAbilityCostChanged.Broadcast(this, NewCost);

	float NewCooldown = GetCoolDown(NewAbilityLevel);
	CDO_AbilityBase->OnAbilityCooldownChanged.Broadcast(this, NewCooldown);
}
```

### **3. UI Integration for Abilities** 
Displays ability-related information such as level, cost, and cooldown through dedicated UI elements.

- We have two widget classes for handling ability slots on the UI: UW_AbilitySlotPanel and UW_AbilitySlot.

- UW_AbilitySlotPanel listens for the AbilitySetGiven delegate. When the ability set is given, it activates and creates UW_AbilitySlot widgets, which are then added to its UHorizontalBox. This class manages the layout and instantiation of the ability slots on the UI.
- UW_AbilitySlot listens for changes to the ability’s cost, cooldown, and level. Whenever any of these properties are updated, it refreshes the UI to reflect the latest values.

```c++
void UW_AbilitySlotPanel::AddAbilitySlotToAbilityPanel(UAbilitySystemComponent* ASC, UGAS_GameplayAbilityBase* AbilityBase)
{
	if (!AbilityBase || !AbilityBase->AbilityIcon || !AbilityBase->GetCooldownGameplayEffect())
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilityBase is null or missing required assets (Icon or Cooldown Gameplay Effect) in %s"), *this->GetName());
		return;
	}

	UW_AbilitySlot* AbilitySlot = Cast<UW_AbilitySlot>(CreateWidget<UW_AbilitySlot>(this, HUDSettings->WBP_AbilitySlot.LoadSynchronous(), FName(AbilityBase->GetName())));
	if (!AbilitySlot)
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilitySlot is couldn't created in %s, cannot initialize ability slots."), *this->GetName());
		return;
	}

	AbilitySlot->CustomInitialize(ASC, AbilityBase);

	HB_Abilities->AddChild(AbilitySlot);
	
	// Adding a spacer to improve the UI layout
	USpacer* Spacer = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass());
	if (Spacer)
	{
		Spacer->SetSize(HUDSettings->SpacerSizeBetweenAbilitySlots);
		HB_Abilities->AddChild(Spacer);
	}
}
```

- Example code for the Ability Slot on the Blueprint side:

![image](https://github.com/user-attachments/assets/fbba4321-601b-408d-89d4-76b9f0e9fa80)

- UW_AbilitySlotPanel also listens for granted abilities and adds them to the ability slot panel when a new ability is granted.

```c++
void UW_AbilitySlotPanel::OnAbilityGranted(UAbilitySystemComponent* ASC, FGameplayAbilitySpec& AbilitySpec)
{
	AddAbilitySlotToAbilityPanel(ASC, Cast<UGAS_GameplayAbilityBase>(AbilitySpec.Ability.Get()));
}
```

## Taking and Dealing Damage
Characters can take damage from various sources, including environmental hazards and enemy attacks. Players can also deal damage using abilities or other gameplay mechanisms. The system includes UI elements that display the amount of damage taken or dealt, providing feedback to the player during combat.

### **1. Dealing Damage Logic**
Enables characters to take damage from the environment or enemies and allows players to deal damage through abilities, weapons, or other means.

- Within the BP_GE_DamageBase, the UEC_DamageBase class handles the process of dealing damage.

![image](https://github.com/user-attachments/assets/be09f2b3-488d-438a-a687-7b5164b0b729)

- All functions related to damage calculation and application are called from the main function, ExecuteWithParams. 

```c++
void UEC_DamageBase::ExecuteWithParams(FExecCalculationParameters Params, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	// Gameplay tags that are attached to the ***Effect*** (not the actor!)

	// If target has a DamageImmune Tag, we shouldn't be able to attack
	if (Params.TargetASC->HasMatchingGameplayTag(GAS_Tags::TAG_Gameplay_DamageImmune))
	{
		return;
	}

	float MitigatedDamage = GetTotalDamage(Params);

	CalculateCritical(Params, MitigatedDamage, OutExecutionOutput);

	CalculateDamageReduction(Params, MitigatedDamage, OutExecutionOutput);

	const float DamageDealt = CalculateHealth(Params, MitigatedDamage, OutExecutionOutput);

	// Trigger events based on the damage dealt
	if (DamageDealt > 0)
	{
		TriggerGameplayEvent(Params, GAS_Tags::TAG_Gameplay_Event_TakeDamage, DamageDealt);
	}

	if (MitigatedDamage >= Params.GetTargetAttributeSet()->GetHealth())
	{
		TriggerGameplayEvent(Params, GAS_Tags::TAG_Gameplay_Event_Death);
	}
	
	float LifeStealDone = .0f;
	CalculateLifeSteal(Params, MitigatedDamage, LifeStealDone, OutExecutionOutput);
}
```
- After the damage undergoes necessary calculations (such as damage reduction), the CalculateHealth function is used to apply the final damage to the target's health attribute.

```c++
float UEC_DamageBase::CalculateHealth(FExecCalculationParameters& Params, float& MitigatedDamage, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const float CurrentTargetHealth = Params.GetTargetAttributeSet()->GetHealth();

	// This clamp prevents us from doing more damage than there is health available.
	const float HealthDamageDone = FMath::Clamp(MitigatedDamage, 0.0f, CurrentTargetHealth);

	// ****************** APPLY DAMAGE ******************
	// Apply that damage to the target's health  
	if (HealthDamageDone > 0)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(Params.GetTargetAttributeSet()->GetHealthAttribute(), EGameplayModOp::Additive, -HealthDamageDone));
	}

	return HealthDamageDone;
}
```

### **2. Take Damage Handling**
- Once the damage is applied, if the resulting damage is greater than zero, the target’s Take Damage ability is triggered. This ability contains the logic that handles the processing of the inflicted damage, allowing the target to react appropriately to the attack.

```c++

// Trigger events based on the damage dealt
if (DamageDealt > 0)
{
        TriggerGameplayEvent(Params, GAS_Tags::TAG_Gameplay_Event_TakeDamage, DamageDealt);
}

void UEC_DamageBase::TriggerGameplayEvent(FExecCalculationParameters& Params, const FGameplayTag& EventTag, float EventMagnitude) const
{
	FGameplayEventData Payload;
	Payload.EventTag = EventTag;
	Payload.Instigator = Params.SourceActor;
	Payload.Target = Params.TargetActor;
	Payload.ContextHandle = Params.GetSpec().GetContext();
	Payload.InstigatorTags = Params.GetSpec().CapturedSourceTags.GetActorTags();
	Payload.EventMagnitude = EventMagnitude;

	Params.TargetASC->HandleGameplayEvent(EventTag, &Payload);
}
```

### **3. Damage UI Feedback**
On the UI side, the damage dealt is displayed using the AGCN_AttachedEffectTextBase GameplayCue, providing visual effects and updates that reflect changes in the character's health and give real-time feedback to the player.

- After the damage effect, visual and audio events are handled via [`Attached Effect Text`](#2-Attached-Effect-Text) and [`Sound Cue Execution`](#1-Sound-GameplayCue) cue. A hit text attached to the target and a sound cue are triggered to provide immediate feedback.

![image](https://github.com/user-attachments/assets/1541ebaf-1855-44c4-a39f-2ecc9c732724)


## Character Death and Respawn
Explanation of the death state and the respawn logic, including spawning points and any conditions for respawning.

- Instead of destroying and spawning characters, we create a more optimized system by simply enabling and disabling their meshes and collisions.

- We use US_SpawnDelegates to manage spawn, despawn, and respawn delegates in a centralized manner. Since it is a Subsystem, we can easily access it from anywhere and listen to the desired delegate.

Here is the header file for US_SpawnDelegates:

```c++
// Spawn refers to the first initialization, 
// ReSpawn refers to subsequent initializations after death
// DeSpawn means the character's death.

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroSpawn, AGAS_PaperCharacterBase*, Hero);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroReSpawn, AGAS_PaperCharacterBase*, Hero);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroDeSpawn, AGAS_PaperCharacterBase*, Hero);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemySpawn, AGAS_PaperCharacterBase*, Enemy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyReSpawn, AGAS_PaperCharacterBase*, Enemy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyDeSpawn, AGAS_PaperCharacterBase*, Enemy);


UCLASS()
class GAS_TEMPLATESP2D_API US_SpawnDelegates : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable)
	FOnHeroSpawn OnHeroSpawn;

	UPROPERTY(BlueprintAssignable)
	FOnHeroReSpawn OnHeroReSpawn;

	UPROPERTY(BlueprintAssignable)
	FOnHeroDeSpawn OnHeroDeSpawn;

	UPROPERTY(BlueprintAssignable)
	FOnEnemySpawn OnEnemySpawn;

	UPROPERTY(BlueprintAssignable)
	FOnEnemyReSpawn OnEnemyReSpawn;

	UPROPERTY(BlueprintAssignable)
	FOnEnemyDeSpawn OnEnemyDeSpawn;
};
```

### **1. Death Mechanic and Logic**
  - A death mechanism triggered within the main function, ExecuteWithParams, of UEC_DamageBase, where the target’s Death Ability is activated when the character's health reaches zero.

```c++
if (MitigatedDamage >= Params.GetTargetAttributeSet()->GetHealth())
{
	TriggerGameplayEvent(Params, GAS_Tags::TAG_Gameplay_Event_Death);
}
```

 - UGA_DeathBase is the main death ability for characters.    

 - In the ActivateAbility function, we disable the character's collision and movement, and broadcast to the delegates.

```c++
void UGA_DeathBase::ActivateAbility(const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData)
{
	// Play AnimSequence.
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	BroadcastDeSpawn();

	if (AGAS_PaperCharacterBase* CharacterBase = Cast<AGAS_PaperCharacterBase>(GetAvatarActorFromActorInfo()))
	{
		CharacterBase->DisableMovement();
		CharacterBase->DisableCollision();

		if (DeathEffectClass)
		{
			UGameplayEffect* ReSpawnEffect = UGAS_EffectBlueprintFunctionLibary::CreateEffectWithTSubclass(DeathEffectClass);
			CharacterBase->GetAbilitySystemComponent()->ApplyGameplayEffectToSelf(ReSpawnEffect, 1, FGameplayEffectContextHandle());
		}
	}
}
```

### **2. Respawn Handling**
The UAC_RespawnBase component is the main class that handles respawning. Two subclasses are derived from this class: UAC_EnemyRespawn and UAC_HeroRespawn.

- The UAC_RespawnBase listens to the Despawn delegate of the relevant character and starts a timer. Once the timer finishes, it enables the character's movement and collisions

Here is the cpp file for UAC_RespawnBase:

```c++
void UAC_RespawnBase::BeginPlay()
{
	Super::BeginPlay();

	BindCharacterDeSpawn();
}

void UAC_RespawnBase::BindCharacterDeSpawn()
{
	// The logic will be implemented in the subclasses.
}

void UAC_RespawnBase::StartCharacterReSpawnCountdown(AGAS_PaperCharacterBase* CharacterBase)
{
	GetWorld()->GetTimerManager().SetTimer(CharacterDeSpawnCountDownTimerHandle, [this, CharacterBase]()
		{
			OnCharacterRespawn(CharacterBase);
		}, 
		ReSpawnDelay, false);
}

void UAC_RespawnBase::OnCharacterRespawn(AGAS_PaperCharacterBase* CharacterBase)
{
	ApplyCharacterReSpawnEffect(CharacterBase);

	CharacterBase->EnableMovement();
	CharacterBase->EnableCollision();
}
```

- Here is the cpp file for UAC_HeroRespawn:
  
```c++
void UAC_HeroRespawn::BindCharacterDeSpawn()
{
    if (US_SpawnDelegates* SpawnDelegatesSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<US_SpawnDelegates>())
    {
        SpawnDelegatesSubsystem->OnHeroDeSpawn.AddDynamic(this, &UAC_RespawnBase::StartCharacterReSpawnCountdown);
    }
}

void UAC_HeroRespawn::OnCharacterRespawn(AGAS_PaperCharacterBase* CharacterBase)
{
    Super::OnCharacterRespawn(CharacterBase);

    SetHeroLocation(CharacterBase);

    if (US_SpawnDelegates* SpawnDelegatesSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<US_SpawnDelegates>())
    {
        SpawnDelegatesSubsystem->OnHeroReSpawn.Broadcast(CharacterBase);
    }
}

void UAC_HeroRespawn::SetHeroLocation(AGAS_PaperCharacterBase* Hero)
{
    if (!Hero)
    {
        return;
    }

    if (UWorld* World = this->GetWorld())
    {
        if (AGameModeBase* AuthGameMode = World->GetAuthGameMode())
        {
            if (AActor* StartPoint = AuthGameMode->FindPlayerStart(Hero->GetController()))
            {
                Hero->SetActorLocation(StartPoint->GetActorLocation());
                Hero->SetActorRotation(StartPoint->GetActorRotation());
            }
        }
    }
}
```
### **3. UI for Death**
In the UI for Death, the UGA_DeathBase applies BP_GE_Death when the character dies.

- This line of code is from UGA_DeathBase, in the ActivateAbility function
  
```c++
if (DeathEffectClass)
{
	UGameplayEffect* ReSpawnEffect = UGAS_EffectBlueprintFunctionLibary::CreateEffectWithTSubclass(DeathEffectClass);
	CharacterBase->GetAbilitySystemComponent()->ApplyGameplayEffectToSelf(ReSpawnEffect, 1, FGameplayEffectContextHandle());
}
```

- This effect triggers UI updates and sound effects using the [`Hero Message HUD`](#1-Hero-Message-HUD) cue and [`Sound Cue Execution`](#1-Sound-GameplayCue) through the GameplayCue system

- This is The BP_GE_Death:
  
![image](https://github.com/user-attachments/assets/929bcea6-beaf-43ac-9244-20da7b002c83)


## Combat Buffs and Debuffs

### **1. Crowd Control Effects**
Explains the implementation of control effects like Slow and Stun using Gameplay Effects.

  - The activation of CC effects is handled through a controlling ability, triggered via a gameplay tag with the "owned tag present" setting.

![image](https://github.com/user-attachments/assets/e3a68c51-9565-4332-8744-3d7961a22a90)


- The gameplay effect grants a tag to the target based on its duration.

![image](https://github.com/user-attachments/assets/1dffc89e-385f-4ee6-837c-1e69fd3b36c2)


- As long as the effect persists, the ability remains active. Once the effect expires, the ability ends, and the relevant logic restores the character to its original state.

```c++
void UGA_StunApplyBase::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* OwnerInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Character = Cast<ACharacter>(OwnerInfo->AvatarActor);
	CharacterMoveComp = Character->GetCharacterMovement();

	CharacterMoveComp->MaxAcceleration = 0;
}

void UGA_StunApplyBase::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	CharacterMoveComp->MaxAcceleration = 2024;;

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
```


### **2. Attributes and Combat Mechanics**
The impact of attributes like Physical Armor, Life Steal, and Critical Damage on gameplay is handled through the UEC_DamageBase class. These effects are processed sequentially within the main function, ExecuteWithParams. 

```c++
void UEC_DamageBase::ExecuteWithParams(FExecCalculationParameters Params, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	// Gameplay tags that are attached to the ***Effect*** (not the actor!)

	// If target has a DamageImmune Tag, we shouldn't be able to attack
	if (Params.TargetASC->HasMatchingGameplayTag(GAS_Tags::TAG_Gameplay_DamageImmune))
	{
		return;
	}

	float MitigatedDamage = GetTotalDamage(Params);

	CalculateCritical(Params, MitigatedDamage, OutExecutionOutput);

	CalculateDamageReduction(Params, MitigatedDamage, OutExecutionOutput);

	const float DamageDealt = CalculateHealth(Params, MitigatedDamage, OutExecutionOutput);

	// Trigger events based on the damage dealt
	if (DamageDealt > 0)
	{
		TriggerGameplayEvent(Params, GAS_Tags::TAG_Gameplay_Event_TakeDamage, DamageDealt);
	}

	if (MitigatedDamage >= Params.GetTargetAttributeSet()->GetHealth())
	{
		TriggerGameplayEvent(Params, GAS_Tags::TAG_Gameplay_Event_Death);
	}
	
	float LifeStealDone = .0f;
	CalculateLifeSteal(Params, MitigatedDamage, LifeStealDone, OutExecutionOutput);
}
```

- First, CalculateCritical is called to determine if a critical hit occurs and modify the damage accordingly.

```c++
void UEC_DamageBase::CalculateCritical(FExecCalculationParameters& Params, float& MitigatedDamage, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	if (Params.EffectAssetTags.HasTag(GAS_Tags::TAG_Gameplay_EffectData_EnableCriticalDamage))
	{
		if (const UAS_Hero* HeroAttributeSet = Cast<UAS_Hero>(Params.GetSourceAttributeSet()))
		{
			float CriticalChance = HeroAttributeSet->GetCriticalChance();
			if (CriticalChance > 0 && CalculateCriticalChance(CriticalChance))
			{
				const float CriticalDamage = MitigatedDamage * (HeroAttributeSet->GetCriticalDamage() / 100);

				if (CriticalDamage > 0)
				{
					// For ShowText gameplaycue, we need to know it is critical 
					Params.MutableSpec->AddDynamicAssetTag(GAS_Tags::TAG_UI_HitTypeText_Critical);
				}

				MitigatedDamage += CriticalDamage;
			}
		}
	}
}
```

- Then, CalculateDamageReduction applies any damage reduction effects, such as armor or resistance.

```c++
void UEC_DamageBase::CalculateDamageReduction(FExecCalculationParameters& Params, float& MitigatedDamage, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const float TotalDamageReduction = GetTotalDamageReduction(Params, MitigatedDamage);
	const float ReducedDamage = MitigatedDamage * (TotalDamageReduction / 100);
	MitigatedDamage -= ReducedDamage;
}
```

- Finally, after calculating the total damage dealt, CalculateLifeSteal is called to heal the player based on the amount of damage dealt.


```c++
void UEC_DamageBase::CalculateLifeSteal(FExecCalculationParameters& Params, float DamageDone, float& HealDone, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	if (Params.EffectAssetTags.HasTag(GAS_Tags::TAG_Gameplay_EffectData_EnableLifeSteal))
	{
		if (const UAS_Hero* HeroAttributeSet = Cast<UAS_Hero>(Params.GetSourceAttributeSet()))
		{
			const float LifeSteal = HeroAttributeSet->GetLifeSteal();
			if (LifeSteal <= 0)
			{
				return;
			}

			HealDone = DamageDone * (LifeSteal / 100);

			// Create Effect and assign spec
			FGameplayEffectSpec LifeStealSpec;
			bool bIsLifeStealSpecValid = UGAS_EffectBlueprintFunctionLibary::CreateInstantEffectSpecWithSetByCallerValue(
				LifeStealSpec, 
				Params.SourceASC, 
				UGE_GainHealth::StaticClass(), 
				GAS_Tags::TAG_Gameplay_EffectData_SetByCaller_GainHealthAmount, 
				HealDone
			);

			if (bIsLifeStealSpecValid) 
			{
				Params.SourceASC->ApplyGameplayEffectSpecToSelf(LifeStealSpec);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("LifeStealSpec is null in %s, cannot life steal apply"), *GetName());
			}
		}
	}
}
```

## Message System
The AGCN_MessageBase class serves as the base class for triggering gameplay messages in the form of UI widgets. 
- It extends the AGCN_ActorBase class and is designed to handle message-related events in the Gameplay Ability System (GAS).
- Two classes derived from it are AGCN_HeroMessageHUD and AGCN_AttachedEffectTextBase.
- This class provides the structure for displaying messages with customizable text, colors, and animations.

```c++
UCLASS()
class GAS_TEMPLATESP2D_API AGCN_MessageBase : public AGCN_ActorBase
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void BP_TriggerWidget(const FWidgetMessageData& MessageData);

	UPROPERTY(EditDefaultsOnly, Category = "MessageConfig")
	FWidgetMessageData WidgetMessageData;
};
```
```c++
USTRUCT(BlueprintType)
struct FWidgetMessageData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "WidgetMessageData")
	FString MessageString = TEXT("");

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WidgetMessageData")
	FSlateColor MessageColor = FSlateColor(FLinearColor::White);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WidgetMessageData")
	TEnumAsByte <EMessageTextAnim> MessageTextAnim = EMessageTextAnim::SlideUpFadeOut;

	FWidgetMessageData() = default;

	FWidgetMessageData(FString InMessageString, FSlateColor InMessageColor, EMessageTextAnim InMessageTextAnim)
		: MessageString(InMessageString),
		MessageColor(MessageColor),
		MessageTextAnim(InMessageTextAnim)
	{}

};
```
### **1. Hero Message HUD**
AGCN_HeroMessageHUD is used to display hero-related messages on the HUD during gameplay events, such as status updates, buffs, or notifications.

- The base class for blueprints:
  
![image](https://github.com/user-attachments/assets/cd60e0b4-25f8-40a2-94e5-6b304aa717f0)

- Here is an example: This is BP_GCN_HeroMessageHUD_Died. When the hero dies, we want to display a message on the HUD with these parameters.

![image](https://github.com/user-attachments/assets/0124441c-ce78-4b35-b669-896d28d43bfd)

- This is from BP_GE_Death, the effect applied when the character dies.

![image](https://github.com/user-attachments/assets/c42e4165-21f4-4a05-8cb6-5a5949e4dc04)



### **2. Attached Effect Text**
AGCN_AttachedEffectTextBase is designed for visually displaying effect-related messages like damage numbers, healing amounts, or critical hit indicators directly on or near affected actors. It provides flexibility in formatting and managing these messages during gameplay.

- The base class for blueprints:

![image](https://github.com/user-attachments/assets/a627444c-6b21-4ea7-b436-503a8396a940)

- Here is an example: This is BP_GCN_AttachedEffectText_Damage. When we attack, we want to display a message attached to the target actor using these parameters.

![image](https://github.com/user-attachments/assets/da7b25cc-e320-4d7b-a7e4-00a6ff4e05df)


## Sound System

### **1. Sound Cue Execution**
The AGCN_SoundBase class is designed to handle sound effects triggered by gameplay events. 
- The core functionality resides in the OnExecuted method, which plays the appropriate sound effect associated with the given actor during a GameplayCue execution.
- This ensures audio feedback is provided for actions like attacks, abilities, or other in-game events, enhancing player immersion and responsiveness.

```c++
void AGCN_SoundBase::OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters)
{
	if (!Target) 
	{
		return;
	}

	if (UAC_GameplayData* DataComponent = Target->GetComponentByClass<UAC_GameplayData>())
	{
		UDA_ActorSounds* SoundsData = DataComponent->GetActorSoundsData();
		if (SoundsData)
		{
			if (SoundsData->TagToSoundMap.Contains(GameplayCueTag))
			{
				USoundCue* AbilitySoundCue = SoundsData->TagToSoundMap[GameplayCueTag];
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), AbilitySoundCue, Target->GetActorLocation());
			}
		}
	}
}
```
- For example, when applying BP_GE_DamageBase, the AGCN_SoundBase automatically plays the target's take-damage sound.
  
![image](https://github.com/user-attachments/assets/2f03cbec-bf22-4d97-8d8a-2361e78f1778)

### **2. Actor Sounds Data**
This data asset allows for flexible and organized sound management. 
- For example, when a specific event occurs (e.g., a character is attacked or uses an ability), the corresponding sound can be easily played by looking up the appropriate USoundCue based on the gameplay tag associated with that event. This provides an efficient way to manage and trigger sounds dynamically during gameplay.

![image](https://github.com/user-attachments/assets/ee6acea6-ceac-4752-b6f8-bbc0b2b3a3bd)


