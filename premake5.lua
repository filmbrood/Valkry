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
IncludeDir["glfw"] = "Valkry/vendor/glfw/include"

group "Dependencies"
include "Valkry/vendor/glfw"

group ""
project "Valkry"
	location "Valkry"
	kind "StaticLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/vendor/glad/src/**.c"
	}

	includedirs
	{
		"%{IncludeDir.glfw}",
		"%{prj.name}/vendor/glad/include"
	}
	
	links
	{
		"GLFW"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		
project "Valkry-Sandbox"
	location "Valkry-Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Valkry/",
		"%{IncludeDir.glfw}",
	}
	
	links
	{
		"Valkry"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"