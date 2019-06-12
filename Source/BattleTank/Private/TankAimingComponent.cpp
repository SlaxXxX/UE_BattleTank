// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAimingComponent.h"

#include "Public/TankBarrel.h"
#include "Public/TankTurret.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "Classes/Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::AimAt(FVector Location, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector Velocity;
	FCollisionResponseParams CollisionParams;

	if (
		UGameplayStatics::SuggestProjectileVelocity(
			this,
			Velocity,
			Barrel->GetSocketLocation(FName("Projectile")),
			Location,
			LaunchSpeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace
		))
	{

		AimDirection = Velocity.GetSafeNormal();

	}
}

void UTankAimingComponent::MoveTurretToAim(float DeltaTime)
{
	if (AimDirection.IsZero()) { return; }

	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaTime, DeltaRotator.Pitch);
	Turret->Rotate(DeltaTime, DeltaRotator.Yaw);
}


