#include "GameSettingMenuWidget.h"
#include "SenceManager.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void UGameSettingMenuWidget::GotoNextLevel()
{
	auto* SenceManager = 
		UGameplayStatics::GetActorOfClass(GetWorld(), ASenceManager::StaticClass());
	if (auto* Manager = Cast<ASenceManager>(SenceManager))
	{
		Manager->GotoNextLevel();
	}
}
