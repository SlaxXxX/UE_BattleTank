// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Classes/GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	void MoveTurretToAim(float DeltaTime);

	void SetBarrelReference(class UTankBarrel* Barrel)
	{
		this->Barrel = Barrel;
	}

	void SetTurretReference(class UTankTurret* Turret)
	{
		this->Turret = Turret;
	}

	void AimAt(FVector Location, float LaunchSpeed);

private:

	FVector AimDirection;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
};
