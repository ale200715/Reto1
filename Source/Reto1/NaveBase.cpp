#include "NaveBase.h"
#include "UObject/ConstructorHelpers.h"

ANaveBase::ANaveBase()
{
    PrimaryActorTick.bCanEverTick = false;

    // Creamos la malla
    MallaNave = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaVisualNave"));
    RootComponent = MallaNave;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CuboAsset(TEXT("/Engine/BasicShapes/Cube"));

    if (MallaNave) {
        RootComponent = MallaNave;

        if (CuboAsset.Succeeded())
        {
            MallaNave->SetStaticMesh(CuboAsset.Object);
        }
        SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
    }
   

    Velocidad = 500.0f;
   
}


void ANaveBase::Mover(float DeltaTime)
{
    FVector NuevaLoc = GetActorLocation() + (GetActorForwardVector() * Velocidad * DeltaTime);
    SetActorLocation(NuevaLoc);
}
