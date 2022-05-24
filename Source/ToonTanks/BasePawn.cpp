// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"

#include "Projectile.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Pawn Capsule collider"));
	RootComponent = CapsuleComponent;

	BaseComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseComponent->SetupAttachment(CapsuleComponent);
	
	TurretComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretComponent->SetupAttachment(BaseComponent);
	
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretComponent);
	// AimPoint = CreateDefaultSubobject<USceneComponent>("Aim Point");
	// AimPoint->SetupAttachment(TurretComponent);
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	// UE_LOG(LogTemp, Error, TEXT("Error from start"));
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// UE_LOG(LogTemp, Warning, TEXT("Tick tock: %s"), *GetActorNameOrLabel());
	// DrawDebugPoint(GetWorld(), AimPoint->GetComponentLocation(), 5, FColor::Red);

}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	const FVector ToTarget = LookAtTarget - TurretComponent->GetComponentLocation();
	const FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	TurretComponent->SetWorldRotation(LookAtRotation);
}

void ABasePawn::Fire()
{
	// DrawDebugSphere(GetWorld(), ProjectileSpawnPoint->GetComponentLocation(),
	// 	12, 16, FColor::Cyan, false, 1);

	GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(),
		ProjectileSpawnPoint->GetComponentRotation());
}

void ABasePawn::RotateTankTurret(float Scale)
{
	TurretComponent->AddLocalRotation(FRotator(0.f, Scale, 0.f));
}