#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameSettingMenuWidget.generated.h"


UCLASS()
class UGameSettingMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void GotoNextLevel();

};