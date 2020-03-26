// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMainMenuWidget.h"
#include "FinalDesignVRGameModeBase.h"
#include "Engine/World.h"


void UGameMainMenuWidget::OnBeginGameBtnClicked()
{
	if (auto* GameModeBase = GetGameMode())
	{
		GameModeBase->SwitchLevel(GameModeBase->GetLevelName(1));
	}
}

AFinalDesignVRGameModeBase* UGameMainMenuWidget::GetGameMode()
{
	if (UWorld* World = GetWorld())
	{
		if (auto* GameModeBase = World->GetAuthGameMode<AFinalDesignVRGameModeBase>())
			return GameModeBase;
	}
	return nullptr;
}
