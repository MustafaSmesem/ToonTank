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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category="Movment")
	float MovementSpeed = 100.f;
	UPROPERTY(EditAnywhere, Category="Movment")
	float RotationSpeed = 20.f;

	APlayerController* TankPlayerController;

	bool bAlive = true;
	
	void Move(float Scale);
	void Turn(float Scale);
	void Zoom();
	void ZoomOut();

	bool CameraState = true;
	UFUNCTION(BlueprintCallable, meta=(AllowPrivateAccess))
	void ToggleCamera();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void HandleDestruction() override;
	APlayerController* GetPlayerController() const { return TankPlayerController; }
	
	bool IsAlive() const
	{
		return bAlive;
	}
};
