// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"

#include "Tank.h"
#include "ToonTankPlayerController.h"
#include "Tower.h"
#include "Kismet/GameplayStatics.h"

void AMainGameModeBase::ActorDied(AActor* DeadActor) const
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if(TankPlayerController)
		{
			TankPlayerController->SetPlayerEnabledState(false);
		}
		
	}
	else if(ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
	}
}

void AMainGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void AMainGameModeBase::HandleGameStart()
{
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	TankPlayerController = Cast<AToonTankPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	if (TankPlayerController)
	{
		TankPlayerController->SetPlayerEnabledState(false);
	}
}
