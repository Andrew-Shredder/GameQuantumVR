#include "QuantumCircuitManager.h"


void UQuantumCircuitManager::AddGate(
	EQuantumGate Gate,
	int32 TargetQubit,
	int32 ControlQubit
)
{
	UE_LOG(LogTemp, Warning, TEXT("AddGate Called!"));

	FQuantumGate NewGate;

	NewGate.GateType = Gate;
	NewGate.TargetQubit = TargetQubit;
	NewGate.ControlQubit = ControlQubit;

	Gates.Add(NewGate);
}


void UQuantumCircuitManager::ClearCircuit()
{
	Gates.Empty();
}


FString UQuantumCircuitManager::GetCircuitText()
{
	FString CircuitText = TEXT("CURRENT CIRCUIT\n\n");

	for (const FQuantumGate& Gate : Gates)
	{
		switch (Gate.GateType)
		{
		case EQuantumGate::H:
			CircuitText += FString::Printf(
				TEXT("H Gate on Qubit %d\n"),
				Gate.TargetQubit
			);
			break;

		case EQuantumGate::X:
			CircuitText += FString::Printf(
				TEXT("X Gate on Qubit %d\n"),
				Gate.TargetQubit
			);
			break;

		case EQuantumGate::Y:
			CircuitText += FString::Printf(
				TEXT("Y Gate on Qubit %d\n"),
				Gate.TargetQubit
			);
			break;

		case EQuantumGate::Z:
			CircuitText += FString::Printf(
				TEXT("Z Gate on Qubit %d\n"),
				Gate.TargetQubit
			);
			break;

		case EQuantumGate::CNOT:
			CircuitText += FString::Printf(
				TEXT("CNOT Gate: Control Qubit %d -> Target Qubit %d\n"),
				Gate.ControlQubit,
				Gate.TargetQubit
			);
			break;

		case EQuantumGate::Measure:
			CircuitText += FString::Printf(
				TEXT("Measure Qubit %d\n"),
				Gate.TargetQubit
			);
			break;

		default:
			break;
		}
	}

	return CircuitText;
}