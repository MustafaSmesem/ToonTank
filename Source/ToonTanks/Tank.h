// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	ATank();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category="Movment")
	float MovementSpeed = 100.f;
	UPROPERTY(EditAnywhere, Category="Movment")
	float RotationSpeed = 20.f;

	void Move(float Scale);
	void Turn(float Scale);
public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};