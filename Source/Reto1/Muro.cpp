#include "Muro.h"
#include "UObject/ConstructorHelpers.h"

AMuro::AMuro()
{
    PrimaryActorTick.bCanEverTick = false;

    
    MuroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMeshInterno"));

    if (MuroMesh)
    {
        RootComponent = MuroMesh;

        static ConstructorHelpers::FObjectFinder<UStaticMesh> CuboAsset(TEXT("/Engine/BasicShapes/Cube"));
        static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialBase(TEXT("/Engine/BasicShapes/BasicShapeMaterial"));
        if (MaterialBase.Succeeded())
        {
            MuroMesh->SetMaterial(0, MaterialBase.Object);
        }

        if (CuboAsset.Succeeded())
        {
            MuroMesh->SetStaticMesh(CuboAsset.Object);
        }

        
        SetActorScale3D(FVector(6.0f, 0.2f, 3.0f));
    }
}

void AMuro::InicializarMuro()
{
    UE_LOG(LogTemp, Log, TEXT("Muro [Base]: Lógica de inicialización ejecutada correctamente."));
}

void AMuro::ConfigurarColorMuro(FLinearColor NuevoColor)
{
    if (MuroMesh)
    {
        UMaterialInstanceDynamic* DynMaterial = MuroMesh->CreateDynamicMaterialInstance(0);

        if (DynMaterial)
        {
            DynMaterial->SetVectorParameterValue(TEXT("Color"), NuevoColor);

            DynMaterial->SetVectorParameterValue(TEXT("Base Color"), NuevoColor);

            DynMaterial->SetVectorParameterValue(TEXT("Emissive"), NuevoColor);
        }
    }
}