#include "FinalDesignVRGameModeBase.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

void AFinalDesignVRGameModeBase::SwitchLevel(const FName& LevelName)
{
	mStreamLevelNameWaitToLoad = LevelName;
	if (!bIsCurStreamLevelUnload)
	{
		if (ULevelStreaming* CurLevel = GetCurLevel())
		{
			bIsCurStreamLevelUnload = true;
			CurLevel->OnLevelUnloaded.AddUniqueDynamic(this, &AFinalDesignVRGameModeBase::OnCurStreamLevelUnloaded);
			FLatentActionInfo LInfo;
			FGuid uid = FGuid::NewGuid();
			LInfo.UUID = uid.D;
			UGameplayStatics::UnloadStreamLevel(this, mCurStreamLevel, LInfo, true);
			return;
		}	
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
	SwitchLevel("Menu");
	AGameModeBase::StartPlay();
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
