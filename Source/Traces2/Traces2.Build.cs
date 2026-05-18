// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Traces2 : ModuleRules
{
	public Traces2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
