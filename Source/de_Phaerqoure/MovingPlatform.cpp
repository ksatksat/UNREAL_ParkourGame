#include "MovingPlatform.h"

#include "Components/StaticMeshComponent.h" 

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;


	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	RootComponent = PlatformMesh;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	if (bStartInverted)
	{
		MoveVelocity = -MoveVelocity;
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += (MoveVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);

	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if (DistanceMoved >= MaxDistance)
	{
		FVector MoveDirection = MoveVelocity.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * MaxDistance);
		SetActorLocation(StartLocation);
		MoveVelocity = -MoveVelocity;
	}
}