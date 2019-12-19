// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ennemi.h"
#include "Patrouilleur.generated.h"

/**
 * 
 */
UCLASS()
class CURSEDLABYRINTH_API APatrouilleur : public AEnnemi
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(EditAnywhere, Category = "Editable", meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> pointsDePassage;

	AActor* pointDePassageCourant;
	int indexPointDePassageCourant = 0;

	UFUNCTION(BlueprintCallable, Category = "Deplacement")
	AActor* changerDestination();
};