#pragma once

#include "CoreMinimal.h"
#include "FinalDesignVRGameModeBase.h"
#include "core/event.h"
#include "GameDefine.h"
#include "SenceManager.generated.h"


class AEnemyProductor;

UCLASS()
class ASenceManager : public AActor
{
	GENERATED_BODY()

public:
	core::event<void(const PlayerCharacterInitInfo&)> CreatePlayerCharacterCallback;

protected:
	void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	//子类基础后重写，可以在关卡开始时设置角色状态
	virtual void ResetPlayerStatus() {};
	AFinalDesignVRGameModeBase* GetGameMode();

protected:
	UPROPERTY(EditDefaultsOnly)
	bool bNeedCreatePlayerCharacter = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FTransform mPlayerInitTrans;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf <AActor> EnemyProductorClass;

	TArray<AActor*> EnemyProducts;
};