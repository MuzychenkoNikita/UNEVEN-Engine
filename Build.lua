workspace "UNEVEN"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	startproject "Editor"

filter "system:windows"
	buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
      
filter "system:macosx"
	architecture "ARM64"
	system "macosx"
	
filter {}

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Engine"
	include "Engine/Build-Engine.lua"
	
group "Editor"
	include "Editor/Build-Editor.lua"