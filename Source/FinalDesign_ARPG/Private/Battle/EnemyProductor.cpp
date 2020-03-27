#include "EnemyProductor.h"
#include "Engine/World.h"
#include "Math/TransformNonVectorized.h"

bool AEnemyProductor::ProductEnemys(int InfoIndex)
{
	if (EnemysInfos.Num() > InfoIndex && InfoIndex >= 0)
	{
		ProductEnemys(EnemysInfos[InfoIndex]);
		return true;
	}
	return false;
}

void AEnemyProductor::ProductEnemys(const FEnemysInfo& Info)
{
	for (int i = 0; i < Info.EnemyNum; i++)
	{
		FTransform CurTrans;
		FVector2D RandPoint = FMath::RandPointInCircle(EnemyProductorRadio);
		FVector CurLocation = GetActorLocation();
		CurLocation.Set(CurLocation.X + RandPoint.X, CurLocation.Y + RandPoint.Y, CurLocation.Z);
		CurTrans.SetLocation(CurLocation);
		FActorSpawnParameters SpawnParams;
		auto* Enemy = GetWorld()->SpawnActor<AVRGameEnemyBase>(*Info.EnemyClass, CurTrans, SpawnParams);
		EnemyList.Push(Enemy);
	}
}

void AEnemyProductor::BeginPlay()
{
	Super::BeginPlay();
	if (AutoProductEnemys)
	{
		for (const auto& EnemyInfo : EnemysInfos)
			ProductEnemys(EnemyInfo);
	}
}

