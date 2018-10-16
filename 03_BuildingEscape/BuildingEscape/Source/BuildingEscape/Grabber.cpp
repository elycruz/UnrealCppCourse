// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include <string>

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting in"));

	UWorld* World = GetWorld();
	PlayerC = World->GetFirstPlayerController();
}

void UGrabber::Grab()
{
}

void UGrabber::Throw()
{
}

void UGrabber::Drop()
{
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player
	AActor* Owner = GetOwner();
	FString ObjectName = Owner->GetName();

	// Get player location
	FVector Location;
	FRotator Rotator;
	PlayerC->GetPlayerViewPoint(
		OUT Location, 
		OUT Rotator
	);
	
	// Log position
	UE_LOG(LogTemp, Warning,
		TEXT("%s{ Location: %s; Position: %s }"), 
		*ObjectName, *Location.ToString(), *Rotator.ToString());
	
	// Check for collision

	// Check if not "grabbing"
	if (isGrabbing) {
		return;
	}

	// If not grabbing, and collided with something, grab that thing

	// If grabbing, allow 'Drop' and 'Throw' of 'Thing'
	
	// ...
}

