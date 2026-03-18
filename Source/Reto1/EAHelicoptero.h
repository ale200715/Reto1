#pragma once

#include "CoreMinimal.h"
#include "EnemigoAereo.h" // Hereda de EnemigoAereo
#include "EAHelicoptero.generated.h"

UCLASS()
class RETO1_API AEAHelicoptero : public AEnemigoAereo {
    GENERATED_BODY()

public:
    // Solo necesitamos el Constructor
    AEAHelicoptero();
};
