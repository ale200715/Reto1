
#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAcuatico.generated.h"

UCLASS()
class RETO1_API AEnemigoAcuatico : public AEnemigo {
    GENERATED_BODY()

public:
    // Esta línea le dice a C++: "Usa mi propio movimiento bajo la plataforma"
    virtual void MoverEnemigo(float DeltaTime) override;
};