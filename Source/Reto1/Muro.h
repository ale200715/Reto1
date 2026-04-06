#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Muro.generated.h"

UCLASS()
class RETO1_API AMuro : public AActor
{
    GENERATED_BODY()

public:
    AMuro();

protected:

    UStaticMeshComponent* MuroMesh;
    void ConfigurarColorMuro(FLinearColor NuevoColor);

public:
    virtual void InicializarMuro();

    UStaticMeshComponent* GetMuroMesh() const { return MuroMesh; }
};