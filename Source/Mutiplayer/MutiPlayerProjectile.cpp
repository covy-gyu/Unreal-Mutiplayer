// Fill out your copyright notice in the Description page of Project Settings.


#include "MutiPlayerProjectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GamePlayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMutiPlayerProjectile::AMutiPlayerProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	//�߻�ü�� �ݸ����� ��Ʈ ������Ʈ ������ �� SphereComponent ����
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	SphereComponent->InitSphereRadius(37.5f);
	SphereComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	RootComponent = SphereComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> DefaultMesh(TEXT("'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(RootComponent);

	//����� �޽� ������ �߰ߵǸ� ����ƽ �޽ÿ� ��ġ/������ ����
	if (DefaultMesh.Succeeded())
	{
		StaticMesh->SetStaticMesh(DefaultMesh.Object);
		StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -37.5f));
		StaticMesh->SetRelativeScale3D(FVector(0.75f, 0.75f, 0.75f));
	}
}

// Called when the game starts or when spawned
void AMutiPlayerProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMutiPlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

