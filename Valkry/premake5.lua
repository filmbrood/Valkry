project "Valkry"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "valkrypch.h"
	pchsource "valkrypch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"*.h",
		"*.cpp",
		"vendor/glm/**.hpp",
		"vendor/glm/**.inl"
	}

	includedirs
	{
		".",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.imgui}"
	}

	links
	{
		"GLFW", "glad", "imgui-docking"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
