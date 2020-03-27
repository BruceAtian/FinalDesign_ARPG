#pragma once

#include "CoreMinimal.h"
#include "FinalDesignVRGameModeBase.h"
#include "core/event.h"
#include "GameDefine.h"
#include "Player/VRGameEnemyBase.h"
#include "EnemyProductor.generated.h"

USTRUCT(BlueprintType)
struct FEnemysInfo
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AVRGameEnemyBase> EnemyClass = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int EnemyNum = 0;
}; 




UCLASS()
class AEnemyProductor : public AActor
{
	GENERATED_BODY()

public:
	bool ProductEnemys(int InfoIndex);
	void ProductEnemys(const FEnemysInfo& Info);

protected:
	virtual void BeginPlay() override;


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool AutoProductEnemys = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float EnemyProductorRadio = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FEnemysInfo> EnemysInfos;

private:
	TArray<AVRGameEnemyBase*> EnemyList;
};

