#include "RotatingPlatform.h"
// We need this include so the compiler knows what a StaticMeshComponent is!
#include "Components/StaticMeshComponent.h"

ARotatingPlatform::ARotatingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create the Cylinder base
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	RootComponent = PlatformMesh;

	// Create the Wall obstacle
	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));
	WallMesh->SetupAttachment(PlatformMesh);

	// Set default position for the wall
	WallMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
}

void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
}

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Determine direction: 1.0 for clockwise, -1.0 for counter-clockwise
	float Direction = bIsClockwise ? 1.0f : -1.0f;

	// Apply the rotation
	AddActorLocalRotation(RotationVelocity * Direction * DeltaTime);
}