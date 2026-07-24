#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuantumCircuitManager.generated.h"


UENUM(BlueprintType)
enum class EQuantumGate : uint8
{
	H,
	X,
	Y,
	Z,
	CNOT,
	Measure
};


USTRUCT(BlueprintType)
struct FQuantumGate
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	EQuantumGate GateType;

	UPROPERTY(BlueprintReadWrite)
	int32 TargetQubit;

	UPROPERTY(BlueprintReadWrite)
	int32 ControlQubit;

	FQuantumGate()
	{
		GateType = EQuantumGate::H;
		TargetQubit = 0;
		ControlQubit = -1;
	}
};


UCLASS(BlueprintType, Blueprintable)
class GAMEQUANTUMVR_API UQuantumCircuitManager : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void AddGate(
		EQuantumGate Gate,
		int32 TargetQubit,
		int32 ControlQubit = -1
	);

	UFUNCTION(BlueprintCallable)
	void ClearCircuit();

	UFUNCTION(BlueprintCallable)
	FString GetCircuitText();

private:

	UPROPERTY()
	TArray<FQuantumGate> Gates;
};