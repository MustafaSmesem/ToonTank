// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Combat")
	UStaticMeshComponent* ProjectileMesh;
	
	UPROPERTY(EditAnywhere, Category="Combat")
	UParticleSystem* HitParticle;	
	UPROPERTY(VisibleAnywhere, Category="Combat")
	UParticleSystemComponent* TrailParticleComponent;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	USoundBase* LaunchSound;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	USoundBase* HitSound;

	UPROPERTY(VisibleAnywhere, Category="Combat")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	TSubclassOf<UCameraShakeBase> HitCameraShakeClass;
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
