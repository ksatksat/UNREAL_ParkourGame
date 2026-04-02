
#include "MyFPSCharacter.h"//
#include "Camera/CameraComponent.h"//
#include "Components/CapsuleComponent.h"//
#include "GameFramework/PlayerController.h"//
#include "Components/InputComponent.h"//(wasd)


AMyFPSCharacter::AMyFPSCharacter()
{//
	PrimaryActorTick.bCanEverTick = false;//

	// 
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));

	// 
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());

	// 
	FirstPersonCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 64.0f));

	// 
	FirstPersonCamera->bUsePawnControlRotation = true;//
}

//
void AMyFPSCharacter::BeginPlay()//
{// 
	Super::BeginPlay();//
}

//
void AMyFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);//

	// 
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyFPSCharacter::MoveRight);

	//
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	//
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	// 
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMyFPSCharacter::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AMyFPSCharacter::StopCrouch);
}

// 
void AMyFPSCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// 
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

//
void AMyFPSCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// 
		AddMovementInput(GetActorRightVector(), Value);
	}
}
void AMyFPSCharacter::StartCrouch()
{
	Crouch();
}

void AMyFPSCharacter::StopCrouch()
{
	UnCrouch();
}