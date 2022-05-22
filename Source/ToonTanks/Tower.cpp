// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(!Tank) return;
	const float Distance = FVector::Dist(Tank->GetActorLocation(), GetActorLocation());
	if (Distance <= FireRange)
	{
		RotateTurret(Tank->GetActorLocation());
	}

}
