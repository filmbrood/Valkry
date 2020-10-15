workspace "Valkry"
	architecture "x64"
	startproject "Valkry-Sandbox"

	configurations
	{
		"Debug",
		"Release",
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glfw"] = "%{wks.location}/Valkry/vendor/glfw/include"
IncludeDir["glad"] = "%{wks.location}/Valkry/vendor/glad/include"
IncludeDir["glm"] = "%{wks.location}/Valkry/vendor/glm"
IncludeDir["imgui"] = "%{wks.location}/Valkry/vendor/imgui-docking"

group "Dependencies"
include "Valkry/vendor/glfw"
include "Valkry/vendor/imgui-docking"
include "Valkry/vendor/glad"

group ""
include "Valkry"
include "Valkry-Sandbox"
