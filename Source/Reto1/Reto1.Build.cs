// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Reto1 : ModuleRules
{
	public Reto1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Reto1",
			"Reto1/Variant_Platforming",
			"Reto1/Variant_Platforming/Animation",
			"Reto1/Variant_Combat",
			"Reto1/Variant_Combat/AI",
			"Reto1/Variant_Combat/Animation",
			"Reto1/Variant_Combat/Gameplay",
			"Reto1/Variant_Combat/Interfaces",
			"Reto1/Variant_Combat/UI",
			"Reto1/Variant_SideScrolling",
			"Reto1/Variant_SideScrolling/AI",
			"Reto1/Variant_SideScrolling/Gameplay",
			"Reto1/Variant_SideScrolling/Interfaces",
			"Reto1/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
