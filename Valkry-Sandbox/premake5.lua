project "Valkry-Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
		"shaders/**.glsl",
	}

	includedirs
	{
		"%{wks.location}/Valkry",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.imgui}"
	}

	links
	{
		"Valkry", "GLFW", "glad", "imgui-docking"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"

	configuration { "linux", "gmake2" }
	  linkoptions { "-ldl -pthread" }
