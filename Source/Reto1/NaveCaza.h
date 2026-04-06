#pragma once

#include "CoreMinimal.h"
#include "NaveBase.h" 
#include "NaveCaza.generated.h"

UCLASS()
class RETO1_API ANaveCaza : public ANaveBase
{
    GENERATED_BODY()

public:
    ANaveCaza();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    FVector PosicionInicial;
    float Amplitud;
    float AmplitudAvance;
    float Frecuencia;
public:
    virtual void Mover(float DeltaTime) override;
};