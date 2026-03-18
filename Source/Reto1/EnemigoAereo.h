#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAereo.generated.h"

UCLASS()
class RETO1_API AEnemigoAereo : public AEnemigo {
    GENERATED_BODY()

public:
    virtual void MoverEnemigo(float DeltaTime) override;
};