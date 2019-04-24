// Fill out your copyright notice in the Description page of Project Settings.


#include "DummyDoor.h"

// Sets default values
ADummyDoor::ADummyDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADummyDoor::BeginPlay()
{
	Super::BeginPlay();
	OpenDoor();
}

// Called every frame
void ADummyDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

void ADummyDoor::OpenDoor()
{
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += 90.f;
	SetActorRotation(NewRotation);
}

