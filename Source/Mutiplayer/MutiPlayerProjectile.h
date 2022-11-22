// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MutiPlayerProjectile.generated.h"

UCLASS()
class MUTIPLAYER_API AMutiPlayerProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMutiPlayerProjectile();

    // �ݸ��� �׽�Ʈ�� ���Ǵ� ���Ǿ� ������Ʈ
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    class USphereComponent* SphereComponent;

    // ������Ʈ�� ���־� ǥ���� �����ϴ� ����ƽ �޽�
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    class UStaticMeshComponent* StaticMesh;

    // �߻�ü �������� ó���ϴ� �����Ʈ ������Ʈ
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    class UProjectileMovementComponent* ProjectileMovementComponent;

    // �߻�ü�� �ٸ� ������Ʈ�� ������ ��ġ�� ������ �� ���Ǵ� ��ƼŬ
    UPROPERTY(EditAnywhere, Category = "Effects")
    class UParticleSystem* ExplosionEffect;

    //�� �߻�ü�� ���� ����� Ÿ�԰� �����
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
    TSubclassOf<class UDamageType> DamageType;

    //�� �߻�ü�� ���ϴ� �����
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage")
    float Damage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};