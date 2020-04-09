#include "FinalDesignVRGameModeBase.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "SenceManager.h"
#include "Engine/GameEngine.h"
#include "Player/VRGameCharacter.h"

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

bool AFinalDesignVRGameModeBase::SwitchNextLevel()
{
	for (int i = 0; i < vLevelNames.Num(); ++i)
	{
		if (mCurStreamLevel == vLevelNames[i] && i + 1 < vLevelNames.Num())
		{
			SwitchLevel(vLevelNames[i + 1]);
			return true;
		}
	}
	return false;
}

void AFinalDesignVRGameModeBase::SetSenceManager(ASenceManager* SManager)
{
	mSenceManager = SManager;
	if (SManager)
	{
		SManager->CreatePlayerCharacterCallback += [this](const PlayerCharacterInitInfo& InitInfo) {
			CreateDefaultPlayerCharacter(InitInfo);
		};
	}
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

void AFinalDesignVRGameModeBase::CreateDefaultPlayerCharacter(const PlayerCharacterInitInfo& TransInfo)
{
	if (mPlayCharacter == nullptr || mPlayCharacter->IsValidLowLevel())
	{
		this->DefaultPawnClass = PlayerCharacterClass;
		auto* DefaultPawn = this->SpawnDefaultPawnAtTransform(GetWorld()->GetFirstPlayerController(), TransInfo.Trans);
		mPlayCharacter = Cast<AVRGameCharacter>(DefaultPawn);
		GetWorld()->GetFirstPlayerController()->Possess(mPlayCharacter);
	}
}
