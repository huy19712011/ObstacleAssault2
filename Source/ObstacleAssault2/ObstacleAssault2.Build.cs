// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ObstacleAssault2 : ModuleRules
{
	public ObstacleAssault2(ReadOnlyTargetRules Target) : base(Target)
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
			"ObstacleAssault2",
			"ObstacleAssault2/Variant_Platforming",
			"ObstacleAssault2/Variant_Platforming/Animation",
			"ObstacleAssault2/Variant_Combat",
			"ObstacleAssault2/Variant_Combat/AI",
			"ObstacleAssault2/Variant_Combat/Animation",
			"ObstacleAssault2/Variant_Combat/Gameplay",
			"ObstacleAssault2/Variant_Combat/Interfaces",
			"ObstacleAssault2/Variant_Combat/UI",
			"ObstacleAssault2/Variant_SideScrolling",
			"ObstacleAssault2/Variant_SideScrolling/AI",
			"ObstacleAssault2/Variant_SideScrolling/Gameplay",
			"ObstacleAssault2/Variant_SideScrolling/Interfaces",
			"ObstacleAssault2/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
