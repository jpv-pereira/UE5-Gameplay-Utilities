#include "UFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "Engine/GameEngine.h"
#include "DrawDebugHelpers.h"
#define DebugPrint(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, x);}

void UFunctionLibrary::OrderByDistance(AActor* TargetActor, TArray<AActor*> inArray, TArray<AActor*>& outArray) {
	TArray<AActor*> validArray;

	for (AActor* actor : inArray) {
		if (actor != nullptr) {
			validArray.Add(actor);
		}
	}

	if (validArray.Num() > 1) {
		validArray.Sort([TargetActor](const AActor& A, const AActor& B) {
			float DistanceA = A.GetDistanceTo(TargetActor);
			float DistanceB = B.GetDistanceTo(TargetActor);
			return DistanceA < DistanceB;
			});
	}
	outArray = validArray;
}

void UFunctionLibrary::GetArrayPercentage(float Percentage, TArray<AActor*> inArray, TArray<AActor*>& outArray) {
	int index = inArray.Num() * Percentage;
	for (int i = 0; i < index; i++) {
		outArray.Add(inArray[i]);
	}
}

void UFunctionLibrary::GetFirstArrayItems(int items, TArray<AActor*> inArray, TArray<AActor*>& outArray) {
	for (int i = 0; i < items; i++) {
		outArray.Add(inArray[i]);
	}
}

void UFunctionLibrary::GetActorArrayCenterPoint(TArray<AActor*> inArray, FVector& outVector) {
	FVector vectorAdd;
	for (AActor* actor : inArray)
	{
		vectorAdd = vectorAdd + actor->GetActorLocation();
	}
	outVector = vectorAdd / inArray.Num();
}

void UFunctionLibrary::GetArrayActorsByVisibility(const UObject* WorldContext, AActor* TargetActor, TArray<AActor*> inArray, float MaxActorDistance, TArray<AActor*>& outArray, bool& foundActor) {

	for (AActor* actor : inArray)
	{
		
		float distance = FVector::Dist(TargetActor->GetActorLocation(), actor->GetActorLocation());

		//Debug
		//FString distanceStr = FString::SanitizeFloat(distance);
		
		if (distance <= MaxActorDistance) {
			FVector Start;
			FRotator TargetRotation;
			TargetActor->GetActorEyesViewPoint(Start, TargetRotation);

			FVector End = actor->GetActorLocation();
			FHitResult Hit;

			FCollisionQueryParams TraceParams;
			TraceParams.AddIgnoredActor(TargetActor);

			if (WorldContext->GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams)) {
				DebugPrint(*Hit.GetActor()->GetName());

				if (Hit.GetActor() == actor) {
					outArray.Add(actor);
					foundActor = true;
				}
			}
			DrawDebugLine(WorldContext->GetWorld(), Start, End, FColor::Orange, false, 2.0f);
		}
	}
	
}

void UFunctionLibrary::GetContainingStrings(TArray<FString> inStringArray, FString inTargetString, TArray<FString>& outArray, bool& foundStrings)
{
	if (!inTargetString.IsEmpty()) {
		for (FString str : inStringArray)
		{
			if (inTargetString.Contains(str))
			{
				outArray.Add(str);
				foundStrings = true;
			}
		}
	}
}


//void GetArrayItemsInDistance(float distance, AActor* TargetActor, TArray<AActor*> inArray, TArray<AActor*>& outArray) {
//	for (inArray actor : AActor) {

//	}
//}