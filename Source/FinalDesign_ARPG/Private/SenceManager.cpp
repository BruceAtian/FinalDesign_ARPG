#include "SenceManager.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "ResourceManager/ResourceManager.h"
#include "Player/VRGameCharacter.h"

void ASenceManager::GotoNextLevel()
{
	GetGameMode()->SwitchNextLevel();
}

void ASenceManager::BeginPlay()
{
	Super::BeginPlay();
	AFinalDesignVRGameModeBase* GameModeBase = GetGameMode();
	if (GameModeBase != nullptr)
	{
		GameModeBase->SetSenceManager(this);
	}
	if (bNeedCreatePlayerCharacter)
	{
		PlayerCharacterInitInfo InitInfo;
		InitInfo.Trans = mPlayerInitTrans;
		CreatePlayerCharacterCallback(InitInfo);
	}
	else
	{
		if (auto* Player = GetGameMode()->GetGamePlayer())
		{
			Player->SetActorTransform(mPlayerInitTrans);
		}
	}

	if (EnemyProductorClass != nullptr)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), EnemyProductorClass, EnemyProducts);
	}

	if (mResourceManager == nullptr)
	{
		mResourceManager = Cast<AResourceManager>
			(UGameplayStatics::GetActorOfClass(GetWorld(), ResourceManagerClass));
	}

	ResetPlayerStatus();
}

void ASenceManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

AFinalDesignVRGameModeBase* ASenceManager::GetGameMode()
{
	if (UWorld* World = GetWorld())
	{
		if (auto* GameModeBase = World->GetAuthGameMode<AFinalDesignVRGameModeBase>())
			return GameModeBase;
	}
	return nullptr;
}

void ASenceManager::SwitchLevelByIndex(int Index)
{
	GetGameMode()->SwitchLevel(GetGameMode()->GetLevelName(Index));
}
