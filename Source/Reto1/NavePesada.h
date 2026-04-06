#pragma once

#include "CoreMinimal.h"
#include "NaveBase.h"
#include "NavePesada.generated.h"

UCLASS()
class RETO1_API ANavePesada : public ANaveBase
{
    GENERATED_BODY()

public:
    ANavePesada();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    FVector PosicionInicial;
    float AmplitudLenta;
    float FrecuenciaLenta;
    float AmplitudAvance;
public:
    virtual void Mover(float DeltaTime) override;
};