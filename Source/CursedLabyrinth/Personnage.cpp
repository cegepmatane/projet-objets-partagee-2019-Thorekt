// Fill out your copyright notice in the Description page of Project Settings.


#include "Vitesse.h"
#include "Engine.h"
#include "Personnage.h"


// Sets default values
APersonnage::APersonnage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	attrapeur = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere de cueillette"));
	attrapeur->AttachTo(RootComponent);
	attrapeur->SetSphereRadius(200.f);
	this->multiplicateurVitesse=1;
}

// Called when the game starts or when spawned
void APersonnage::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APersonnage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APersonnage::prendre(){
	TArray<AActor*> listeObjets;
	this->attrapeur->GetOverlappingActors(listeObjets);

	for (int32 position = 0; position < listeObjets.Num(); position++) {
		AVitesse* vitesse = Cast<AVitesse>(listeObjets[position]);
		if (vitesse && !vitesse->IsPendingKill()) {
			vitesse->estAttrape();
			this->multiplicateurVitesse++;
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "multiplicateur" + FString::SanitizeFloat(this->multiplicateurVitesse));

		}
			

	}

}


int APersonnage::getMultiplicateurVitesse() {
	return this->multiplicateurVitesse;

}

