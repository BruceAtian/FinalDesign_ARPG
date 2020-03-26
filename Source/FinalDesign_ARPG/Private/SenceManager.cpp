#include "SenceManager.h"
#include "Engine/World.h"


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
		CreatePlayerCharacterCallback(InitInfo);
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