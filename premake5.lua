
workspace "Hazel"

	architecture "x64"

	configurations {"Debug", "Release", "Dist"}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Hazel/vendor/GLFW/include"

include "Hazel/vendor/GLFW"


project "Hazel"

	location "Hazel"

	kind "SharedLib"

	language "C++"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")

	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Hazel/src/hzpch.cpp"

	
	files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

	includedirs {
	
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
	}
	
	links
	{
		"GLFW",
		"opengl32.lib",
		"Dwmapi.lib"
	}

	filter "system:windows"

		cppdialect "C++17"

		staticruntime "On"
		
		systemversion "latest"
	
		defines {
			"HZ_BUILD_DLL", "HZ_PLATFORM_WINDOWS", "_WINDLL"
		}
	
		postbuildcommands {
			
			--first time maybe lost ddl ,so you need to click run button twice times
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "HZ_RELEASE"
	
		optimize "On"
	
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"

	--[[filter {"system:windows", "configurations:Release"}
		
		buildoptions "/MT"
	--]]


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
	includedirs {
		"Hazel/vendor/spdlog/include",
		"Hazel/src"
	}

	links {"Hazel"}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines {"HZ_PLATFORM_WINDOWS"}
	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"
	
		