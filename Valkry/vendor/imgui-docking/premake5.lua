project "imgui-docking"
  kind "StaticLib"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "*.h", "*.cpp"
  }

  includedirs
  {
    "%{wks.location}/Valkry/vendor/glfw/include",
    "%{wks.location}/Valkry/vendor/glad/include"
  }

  links
  {
    "GLFW"
  }

  filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
