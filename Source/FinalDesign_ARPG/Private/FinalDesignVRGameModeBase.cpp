#include "FinalDesignVRGameModeBase.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

void AFinalDesignVRGameModeBase::SwitchLevel(const FName& LevelName)
{
	mStreamLevelNameWaitToLoad = LevelName;
	if (!bIsCurStreamLevelUnload)
	{
		bIsCurStreamLevelUnload = true;
		ULevelStreaming* CurLevel = GetCurLevel();
		CurLevel->OnLevelLoaded.AddUniqueDynamic(this, &AFinalDesignVRGameModeBase::OnCurStreamLevelUnloaded);
		FLatentActionInfo LInfo;
		FGuid uid = FGuid::NewGuid();
		LInfo.UUID = uid.D;
		UGameplayStatics::UnloadStreamLevel(this, mCurStreamLevel, LInfo, true);
		return;
	}
	OnCurStreamLevelUnloaded();
}

ULevelStreaming* AFinalDesignVRGameModeBase::GetCurLevel() const
{
	if (UWorld* World = GetWorld())
	{
		for (ULevelStreaming* LevelStream : World->GetStreamingLevels())
		{
			if (LevelStream != nullptr && LevelStream->IsLevelVisible())
				return LevelStream;
		}
	}
	return nullptr;
}

FName AFinalDesignVRGameModeBase::GetLevelName(int Index)
{
	if (vLevelNames.Num() > Index)
		return vLevelNames[Index];
	return "";
}

void AFinalDesignVRGameModeBase::StartPlay()
{
	if (vLevelNames.Num() > 0)
		mCurStreamLevel = vLevelNames[0];

}

void AFinalDesignVRGameModeBase::OnCurStreamLevelUnloaded()
{
	FLatentActionInfo LInfo;
	FGuid uid = FGuid::NewGuid();
	LInfo.UUID = uid.D;
	UGameplayStatics::LoadStreamLevel(this, mStreamLevelNameWaitToLoad, true, true, LInfo);
	mCurStreamLevel = mStreamLevelNameWaitToLoad;
	mStreamLevelNameWaitToLoad = "";
	bIsCurStreamLevelUnload = false;
}
