#pragma once

#include "CoreMinimal.h"
#include "Muro.h" 
#include "MuroMovible.generated.h"

UCLASS()
class RETO1_API AMuroMovible : public AMuro
{
    GENERATED_BODY()

public:
    AMuroMovible();

protected:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    FVector Direccion;
    float Velocidad;
    float Amplitud;
    
    FVector PosicionInicial;

public:
    virtual void InicializarMuro() override;
};