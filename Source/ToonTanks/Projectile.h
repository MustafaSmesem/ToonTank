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
	UPROPERTY(EditDefaultsOnly, Category="Compat")
	UStaticMeshComponent* ProjectileMesh;
	
	UPROPERTY(EditAnywhere, Category="Compat")
	UParticleSystem* HitParticle;	
	UPROPERTY(VisibleAnywhere, Category="Compat")
	UParticleSystemComponent* TrailParticleComponent;

	UPROPERTY(EditDefaultsOnly, Category="Compat")
	USoundBase* LaunchSound;

	UPROPERTY(EditDefaultsOnly, Category="Compat")
	USoundBase* HitSound;

	UPROPERTY(VisibleAnywhere, Category="Compat")
	class UProjectileMovementComponent* ProjectileMovementComponent;
	
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
