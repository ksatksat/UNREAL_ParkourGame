// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class de_PhaerqoureTarget : TargetRules
{
	public de_PhaerqoureTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "de_Phaerqoure" } );
	}
}
