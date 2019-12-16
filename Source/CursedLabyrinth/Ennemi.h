// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ennemi.generated.h"

UCLASS()
class CURSEDLABYRINTH_API AEnnemi : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnnemi();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Detection")
	void joueurDetecter(AActor* joueur);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Editable", meta = (AllowPrivateAccess = "true"))
	class USpotLightComponent* lumiereDetection;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Detection", meta = (AllowPrivateAccess = "true"))	
	class UStaticMeshComponent* detection;


	UPROPERTY(EditAnywhere, Category = "Editable", meta = (AllowPrivateAccess = "true"))
	class AActor* debut;

};
