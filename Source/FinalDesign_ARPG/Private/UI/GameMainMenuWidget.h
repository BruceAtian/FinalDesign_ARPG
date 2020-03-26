#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameMainMenuWidget.generated.h"


class AFinalDesignVRGameModeBase;

UCLASS()
class UGameMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
		void OnBeginGameBtnClicked();

	AFinalDesignVRGameModeBase* GetGameMode();
private:
};
