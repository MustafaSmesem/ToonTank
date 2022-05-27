// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	virtual void HandleDestruction();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void RotateTurret(FVector LookAtTarget);
	void RotateTankTurret(float Scale);
	void UpTankTurret(float Scale);
	void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	class UCapsuleComponent* CapsuleComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	UStaticMeshComponent* BaseComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	UStaticMeshComponent* TurretComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	USceneComponent* ProjectileSpawnPoint;
	
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	// USceneComponent* AimPoint;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	TSubclassOf<class AProjectile> ProjectileClass;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
