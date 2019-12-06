// Fill out your copyright notice in the Description page of Project Settings.


#include "Cellule.h"
#include "Engine/World.h"
#include "Components/BoxComponent.h"

// Sets default values
ACellule::ACellule()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->ouverte = false;
	this->murs[0] = true;
	this->murs[1] = true;

	this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	this->lieuApparitionMurX = CreateDefaultSubobject<UBoxComponent>(TEXT("lieuApparitionMurX"));
	this->lieuApparitionMurY = CreateDefaultSubobject<UBoxComponent>(TEXT("lieuApparitionMurY"));
	this->lieuApparitionMurX->AttachTo(this->RootComponent);
	this->lieuApparitionMurY->AttachTo(this->RootComponent);
}

// Called when the game starts or when spawned
void ACellule::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACellule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACellule::setOuverte(bool etat) {
	this->ouverte = etat;
}

bool ACellule::estOuverte() {
	return this->ouverte;
}

void ACellule::setMur(int index, bool etat) {
	this->murs[index] = etat;
}

bool ACellule::getMur(int index) {
	return this->murs[index];
}

void ACellule::setCellulesAdjacentes(int index, ACellule *cellule) {
	this->cellulesAdjacentes[index] = cellule;
}

ACellule* ACellule::getCellulesAdjacentes(int index) {
	return this->cellulesAdjacentes[index];
}

void ACellule::setCoordonnee(int x, int y) {
	this->coordX = x;
	this->coordY = y;
}
int ACellule::getCoordX(){
	return this->coordX;
}
int ACellule::getCoordY(){
	return this->coordY;
}


void ACellule::ouvrirMur(int index) {

	setMur(index, false);

}

void ACellule::ouvrirCellule() {
	bool cellulesAdjacentesToutesOuverte = resteCellulesAdjacentesPasOuverte();
	setOuverte(true);

	TArray<int16> indexRestant;

	indexRestant.Add(0);
	indexRestant.Add(1);
	indexRestant.Add(2);
	indexRestant.Add(3);

	while (cellulesAdjacentesToutesOuverte && indexRestant.Num() != 0)
	{	
	
		int random = rand() % (indexRestant.Num());

		int indexProchaineCellule = indexRestant[random];


		if ((indexProchaineCellule == 0 && getCoordX() != 9) ||
			(indexProchaineCellule == 1 && getCoordY() != 9) || 
			(indexProchaineCellule == 2 && getCoordX() != 0) ||
			(indexProchaineCellule == 3 && getCoordY() != 0))
		{
			if (!this->cellulesAdjacentes[indexProchaineCellule]->estOuverte()) {
				if (indexProchaineCellule == 0 || indexProchaineCellule == 1) {
					this->ouvrirMur(indexProchaineCellule);
				}
				else if (indexProchaineCellule == 2 || indexProchaineCellule == 3) {
					this->cellulesAdjacentes[indexProchaineCellule]->ouvrirMur(indexProchaineCellule-2);
				}
				this->cellulesAdjacentes[indexProchaineCellule]->ouvrirCellule();

			}
		}

		indexRestant.RemoveAt(random);

		cellulesAdjacentesToutesOuverte = resteCellulesAdjacentesPasOuverte();
	}
}

bool ACellule::resteCellulesAdjacentesPasOuverte() {
	bool reste = false;
	if (getCoordX() != 9 ) {
		if (!this->cellulesAdjacentes[0]->estOuverte()) {
			reste = true;
		}
	}
	if (getCoordY() != 9  ) {
		if (!this->cellulesAdjacentes[1]->estOuverte()) {
			reste = true;
		}
	}
	if (getCoordX() != 0 ) {
		if (!this->cellulesAdjacentes[2]->estOuverte()) {
			reste = true;
		}
	}
	if (getCoordY() != 0) {
		if (!this->cellulesAdjacentes[3]->estOuverte()) {
			reste = true;
		}
	}
	return reste;
}

void ACellule::genererMurs() {
	UWorld* monde = GetWorld();

	if (NULL == this->mur) return;
	if (NULL == monde) return;

	FActorSpawnParameters parametresApparition;
	parametresApparition.Owner = this;
	parametresApparition.Instigator = Instigator;


	if (this->murs[0] && getCoordX() != 9) {
		monde->SpawnActor<AActor>(this->mur, this->lieuApparitionMurX->GetComponentLocation(), this->lieuApparitionMurX->GetComponentRotation());
	}
	if (this->murs[1] && getCoordY() != 9) {
		monde->SpawnActor<AActor>(this->mur, this->lieuApparitionMurY->GetComponentLocation(), this->lieuApparitionMurY->GetComponentRotation());
	}
}