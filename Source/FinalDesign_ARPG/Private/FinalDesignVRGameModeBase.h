#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/LevelStreaming.h"
#include "FinalDesignVRGameModeBase.generated.h"

class ASenceManager;

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
	void SetSenceManager(ASenceManager* SManager)
	{
		mSenceManager = SManager;
	};

	ASenceManager* GetSenceManager()
	{ return mSenceManager; };


protected:
	virtual void StartPlay() override;


private:
	//Level
	void OnCurStreamLevelUnloaded();
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FName> vLevelNames;

private:
	ASenceManager* mSenceManager = nullptr;
	bool bIsCurStreamLevelUnload = false;
	FName mStreamLevelNameWaitToLoad = "";
	FName mCurStreamLevel = "";
};
