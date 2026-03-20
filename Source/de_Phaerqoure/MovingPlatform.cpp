#include "MovingPlatform.h"
// --- ADD THIS LINE BELOW ---
#include "Components/StaticMeshComponent.h" 

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	// Now that we included StaticMeshComponent.h, the line below will work!
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	RootComponent = PlatformMesh;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	// If the user checked "bStartInverted" in the editor, flip the direction!
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