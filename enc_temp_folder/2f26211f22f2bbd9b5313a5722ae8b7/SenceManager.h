#pragma once

#include "CoreMinimal.h"
#include "FinalDesignVRGameModeBase.h"
#include "SenceManager.generated.h"


UCLASS()
class ASenceManager : public AActor
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

	AFinalDesignVRGameModeBase* GetGameMode();
};