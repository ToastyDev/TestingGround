// Fill out your copyright notice in the Description page of Project Settings.

#include "FloatyFurniture.h"


// Sets default values
AFloatyFurniture::AFloatyFurniture()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatyFurniture::BeginPlay()
{
	Super::BeginPlay();
	FString ActorName = GetName();
	FString ActorLabel = GetActorLabel();
	FTransform ActorTransform = GetTransform();
	UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *ActorName);
	UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *ActorLabel);
	UE_LOG(LogTemp, Warning, TEXT("Location: %s"), ActorTransform.ToString()); 
	
}

// Called every frame
void AFloatyFurniture::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	if (NewLocation.Z <= 200)
		NewLocation.Z += 20 * DeltaTime;
	else if (NewLocation.Z >= 500)
		NewLocation.Z -= 20 * DeltaTime;
	SetActorLocation(NewLocation);

}

