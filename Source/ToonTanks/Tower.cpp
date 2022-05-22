// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandler, this,
		&ATower::CheckFireCondition, FireRate, true);
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (InFireRange())
		RotateTurret(Tank->GetActorLocation());

}

void ATower::CheckFireCondition()
{
	if (InFireRange()) Fire();
}

bool ATower::InFireRange()
{
	if(!Tank) return false;
	float Distance = FVector::Dist(Tank->GetActorLocation(), GetActorLocation());
	if (Distance > FireRange) return false;
	return true;
}