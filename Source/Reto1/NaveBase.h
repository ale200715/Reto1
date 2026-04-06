#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "NaveBase.generated.h"

UCLASS()
class RETO1_API ANaveBase : public AActor
{
    GENERATED_BODY()

public:
    ANaveBase();

protected:

    UStaticMeshComponent* MallaNave;

    float Velocidad;

public:
    virtual void Mover(float DeltaTime);
    UStaticMeshComponent* GetMallaNave() const { return MallaNave; }
};