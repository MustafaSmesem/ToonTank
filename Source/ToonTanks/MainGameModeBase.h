// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AMainGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* DeadActor);
protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);
private:
	class ATank* Tank;
	class AToonTankPlayerController* TankPlayerController;

	UPROPERTY(EditAnywhere, Category="Game Setup")
	float GameStartDelay = 3.f;
	
	void HandleGameStart();

	int32 TargetTowers = 0;
	int32 GetTowersCount() const;
};
