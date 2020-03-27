#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/LevelStreaming.h"
#include "core/event.h"
#include "GameDefine.h"
#include "FinalDesignVRGameModeBase.generated.h"

class ASenceManager;
class AVRGameCharacter;

UCLASS()
class AFinalDesignVRGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	//Level
	void SwitchLevel(const FName& LevelName);
	ULevelStreaming* GetCurLevel() const;
	FName GetLevelName(int Index);

	//SenceManager
	void SetSenceManager(ASenceManager* SManager);
	ASenceManager* GetSenceManager()
	{ return mSenceManager; };

	//Player
	AVRGameCharacter* GetGamePlayer() const { return mPlayCharacter;};


protected:
	virtual void StartPlay() override;

	//Level
	UFUNCTION(BlueprintCallable)
	void OnCurStreamLevelUnloaded();
private:

	//player
	void CreateDefaultPlayerCharacter(const PlayerCharacterInitInfo& TransInfo);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FName> vLevelNames;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AVRGameCharacter> PlayerCharacterClass;

private:
	ASenceManager* mSenceManager		= nullptr;
	bool bIsCurStreamLevelUnload		= false;
	FName mStreamLevelNameWaitToLoad	= "";
	FName mCurStreamLevel				= "";
	AVRGameCharacter* mPlayCharacter	= nullptr;
};
