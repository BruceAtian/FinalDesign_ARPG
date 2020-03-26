#include "SenceManager.h"
#include "Engine/World.h"


void ASenceManager::BeginPlay()
{
	AFinalDesignVRGameModeBase* GameModeBase = GetGameMode();
	if (GameModeBase != nullptr)
	{
		GameModeBase->SetSenceManager(this);
	}
	
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