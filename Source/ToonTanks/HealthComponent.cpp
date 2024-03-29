// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "MainGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);

	ToonTankGameMode = Cast<AMainGameModeBase>(UGameplayStatics::GetGameMode(this));
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* Type, AController* Instigator, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Error, TEXT("[%f] Oh my my I [%s] get a damage [%f] from [%s]."), Health,
		*DamagedActor->GetActorNameOrLabel(), Damage, *DamageCauser->GetActorNameOrLabel());
	if (Damage <= 0.f) return;
	Health -= Damage;
	if (Health <= 0 && ToonTankGameMode)
	{
		ToonTankGameMode->ActorDied(DamagedActor);
	}
}
