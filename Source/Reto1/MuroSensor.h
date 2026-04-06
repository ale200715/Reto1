#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroSensor.generated.h"

UCLASS()
class RETO1_API AMuroSensor : public AMuro
{
    GENERATED_BODY()

public:

    AMuroSensor();

protected:
   
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    float DistanciaDeteccion;

    bool bEstaActivado;

public:
    virtual void InicializarMuro() override;
};