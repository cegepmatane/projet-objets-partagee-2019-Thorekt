// Fill out your copyright notice in the Description page of Project Settings.


#include "Cellule.h"

// Sets default values
ACellule::ACellule()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->ouverte = false;
	this->murs[0] = true;
	this->murs[1] = true;
	this->murs[2] = true;
	this->murs[3] = true;
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