// Fill out your copyright notice in the Description page of Project Settings.


#include "Ennemi.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SpotLightComponent.h"

// Sets default values
AEnnemi::AEnnemi()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	this->lumiereDetection = CreateDefaultSubobject<USpotLightComponent>(TEXT("LumiereDetection"));
	this->lumiereDetection->AttachTo(this->RootComponent);
	this->detection = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Detection"));
	this->detection->AttachTo(this->RootComponent);
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

void AEnnemi::joueurDetecter(AActor* joueur) {
	if (this->debut != NULL) {
		joueur->SetActorLocation(this->debut->GetActorLocation());
	}
	
}

