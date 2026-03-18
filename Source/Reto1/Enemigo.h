#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Enemigo.generated.h"

UCLASS()
class RETO1_API AEnemigo : public AActor {
    GENERATED_BODY()

public:
    AEnemigo();

    UStaticMeshComponent* MallaEnemigo;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    FVector PosicionInicial;
    int32 Direccion = 1;

    UPROPERTY(EditAnywhere)
    float Velocidad = 250.0f;

    UPROPERTY(EditAnywhere)
    float DistanciaMaxima = 400.0f;

    virtual void MoverEnemigo(float DeltaTime);
};
