// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReporter.h"
#include "Gameframework/Actor.h"
#include <string>

// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	FString ObjectName = Owner->GetName();
	FVector Location = Owner->GetActorLocation();
	FString ObjectPos = (
		"X: " + std::to_string(Location.X) + ", " +
		"Y: " + std::to_string(Location.Y).c_str() + ", " +
		"Z: " + std::to_string(Location.Z).c_str()
		).c_str();
		
	// Simple logging with unreal
	UE_LOG(LogTemp, Warning, 
		TEXT("Position report for %s;\nLocation: %s"), *ObjectName, *ObjectPos);
}


// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

