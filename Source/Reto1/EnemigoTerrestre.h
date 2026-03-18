#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoTerrestre.generated.h"

UCLASS()
class RETO1_API AEnemigoTerrestre : public AEnemigo {
    GENERATED_BODY()

public:
    // Esta línea le dice a C++: "Usa mi propio movimiento en la plataforma"
    virtual void MoverEnemigo(float DeltaTime) override;
};