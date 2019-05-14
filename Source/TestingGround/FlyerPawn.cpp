// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyerPawn.h"
#include "Classes/Components/InputComponent.h"
#include "Classes/GameFramework/FloatingPawnMovement.h"
#include "Classes/GameFramework/SpringArmComponent.h"
#include "Classes/Camera/CameraComponent.h"

// Sets default values
AFlyerPawn::AFlyerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//set default sub components
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("PawnMeshComponent");

	CameraArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
	CameraArm->SetupAttachment(StaticMesh);
	CameraArm->TargetArmLength = 500.f;

	Camera = CreateDefaultSubobject<UCameraComponent>("PawnCameraComponent");
	Camera->SetupAttachment(CameraArm);

	SetRootComponent(StaticMesh);

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;
	
}

// Called when the game starts or when spawned
void AFlyerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

//Movement functions
void AFlyerPawn::MoveForward(float amount)
{
	FloatingPawnMovement->AddInputVector(GetActorForwardVector() * amount);
}

void AFlyerPawn::MoveRight(float amount)
{
	FloatingPawnMovement->AddInputVector(GetActorRightVector() * amount);
}

void AFlyerPawn::Turn(float amount)
{
	AddControllerYawInput(amount);
}

void AFlyerPawn::LookUp(float amount)
{
	AddControllerPitchInput(amount);
}

// Called every frame
void AFlyerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFlyerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFlyerPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFlyerPawn::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AFlyerPawn::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AFlyerPawn::LookUp);
}

