// Fill out your copyright notice in the Description page of Project Settings.


#include "Patrouilleur.h"

AActor* APatrouilleur::changerDestination() {
	if (pointsDePassage.Num() == 0)
		return this;
	pointDePassageCourant = pointsDePassage[indexPointDePassageCourant];
	indexPointDePassageCourant += 1;
	if (indexPointDePassageCourant <= pointsDePassage.Num())
		indexPointDePassageCourant = 0;
	return this->pointDePassageCourant;
}