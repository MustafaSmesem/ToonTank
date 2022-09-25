// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Player Spring Arm");
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>("Player Cam");
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	TankPlayerController = Cast<APlayerController>(GetController());
}

void ATank::HandleDestruction()
{
	Super::HandleDestruction();
	bAlive = false;
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
}
// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (TankPlayerController)
	{
		FHitResult HitResult;
		TankPlayerController->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
		// DrawDebugSphere(GetWorld(), HitResult.ImpactPoint,
		// 	10, 16, FColor::Red,
		// 	false, -1.f);
		RotateTurret(HitResult.ImpactPoint);
	}
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
	// PlayerInputComponent->BindAxis(TEXT("RotateTurret"), this, &ATank::RotateTankTurret);
	// PlayerInputComponent->BindAxis(TEXT("UpTurret"), this, &ATank::UpTankTurret);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
	PlayerInputComponent->BindAction(TEXT("Zoom"), IE_Pressed, this, &ATank::Zoom);
	PlayerInputComponent->BindAction(TEXT("Zoom"), IE_Released, this, &ATank::ZoomOut);
	PlayerInputComponent->BindAction(TEXT("CamToggle"), IE_Pressed, this, &ATank::ToggleCamera);
}

void ATank::Move(const float Scale)
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = Scale * MovementSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(const float Scale)
{
	FRotator DeltaRotation = FRotator::ZeroRotator;
	DeltaRotation.Yaw = Scale * RotationSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(DeltaRotation, true);
}

void ATank::ToggleCamera()
{
	if (CameraState)
	{
		SpringArm->TargetArmLength = 1500;
		SpringArm->AddLocalRotation(FQuat(FRotator(-40, 0, 0)));
	} else
	{
		SpringArm->TargetArmLength = 700;
		SpringArm->AddLocalRotation(FQuat(FRotator(40, 0, 0)));
	}
	CameraState = !CameraState;
}

void ATank::Zoom()
{
	if (!CameraState) ToggleCamera();
	SpringArm->TargetArmLength = -100;
	SpringArm->AddLocalRotation(FQuat(FRotator(50, 0, 0)));
}

void ATank::ZoomOut()
{
	SpringArm->TargetArmLength = 900;
	SpringArm->AddLocalRotation(FQuat(FRotator(-50, 0, 0)));
}

