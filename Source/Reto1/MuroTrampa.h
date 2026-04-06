#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroTrampa.generated.h"

UCLASS()
class RETO1_API AMuroTrampa : public AMuro
{
    GENERATED_BODY()

public:
    AMuroTrampa();

    virtual void InicializarMuro() override;

protected:
    virtual void BeginPlay() override;

    void AlternarEstado();

    void TeletransportarMuro();

    FTimerHandle TimerTrampa;

    float TiempoCambio;
    float RadioAleatorio;
};