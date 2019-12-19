// Fill out your copyright notice in the Description page of Project Settings.


#include "Surveilleur.h"
#include "Engine.h"

void ASurveilleur::clignoter(float temps) {
	this->tempsActuel += temps;
	if (this->tempsRestant <= this->tempsActuel) {
		this->tempsRestant = tempsActuel + tempsBattement;
		this->SetActorHiddenInGame(!this->bHidden);
		this->SetActorEnableCollision(!this->GetActorEnableCollision());
	}
}