// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ennemi.h"
#include "Surveilleur.generated.h"

/**
 * 
 */
UCLASS()
class CURSEDLABYRINTH_API ASurveilleur : public AEnnemi
{
	GENERATED_BODY()
private:
    float tempsRestant = 0.0f;
    float tempsBattement = 0.4f;
    float tempsActuel = 0.0f;
protected:


    UFUNCTION(BlueprintCallable, Category = "Detection")
    void clignoter(float tempsActuel);

};
