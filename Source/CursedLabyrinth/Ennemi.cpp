// Fill out your copyright notice in the Description page of Project Settings.


#include "Ennemi.h"
#include "Components/BoxComponent.h"
#include "Components/SpotLightComponent.h"

// Sets default values
AEnnemi::AEnnemi()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	this->lumiereDetection = CreateDefaultSubobject<USpotLightComponent>(TEXT("LumiereDetection"));
	lumiereDetection->AttachTo(this->RootComponent);
}

// Called when the game starts or when spawned
void AEnnemi::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnnemi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

