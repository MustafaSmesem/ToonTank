// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	class ATank* Tank;
	
	UPROPERTY(EditAnywhere, Category="Compat")
	float FireRange = 600;
	FTimerHandle FireRateTimerHandler;
	UPROPERTY(EditAnywhere, Category="Compat")
	float FireRate = 2.f;

	void CheckFireCondition();
	bool InFireRange();
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
