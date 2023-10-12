#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UFunctionLibrary.generated.h"

UCLASS()
class GAME_API UFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "UFunctionLibrary", meta = (WorldContext = "WorldContextObject", DisplayName = "Sort Actors by Distance"))
	static void OrderByDistance(AActor* TargetActor, TArray<AActor*> inArray, TArray<AActor*>& outArray);

	UFUNCTION(BlueprintCallable, Category = "UFunctionLibrary", meta = (WorldContext = "WorldContextObject", DisplayName = "Get Percentage of Actors"))
	static void GetArrayPercentage(float Percentage, TArray<AActor*> inArray, TArray<AActor*>& outArray);

	UFUNCTION(BlueprintCallable, Category = "UFunctionLibrary", meta = (WorldContext = "WorldContextObject", DisplayName = "Get First N Actors"))
	static void GetFirstArrayItems(int items, TArray<AActor*> inArray, TArray<AActor*>& outArray);
	
	UFUNCTION(BlueprintCallable, Category = "UFunctionLibrary", meta = (WorldContext = "WorldContextObject", DisplayName = "Get Center Point of Actor Array"))
	static void GetActorArrayCenterPoint(TArray<AActor*> inArray, FVector& outVector);

	UFUNCTION(BlueprintCallable, Category = "UFunctionLibrary", meta = (WorldContext = "WorldContextObject", DisplayName = "Filter Actors by Visibility"))
	static void GetArrayActorsByVisibility(const UObject* WorldContext, AActor* TargetActor, TArray<AActor*> inArray, float MaxActorDistance, TArray<AActor*>& outArray, bool& foundActor);

	UFUNCTION(BlueprintCallable, Category = "UFunctionLibrary", meta = (WorldContext = "WorldContextObject", DisplayName = "Find Strings in Array"))
	static void GetContainingStrings(TArray<FString> inStringArray, FString inTargetString, TArray<FString>& outArray, bool& foundStrings);

	//UFUNCTION(BlueprintCallable, Category = "UFunctionLibrary", meta = (WorldContext = "WorldContextObject", DisplayName = "Get Actors within Distance"))
	//static void GetArrayItemsInDistance(float distance, AActor* TargetActor,TArray<AActor*> inArray, TArray<AActor*>& outArray);
};
