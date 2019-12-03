
workspace "JumboEngine"
	architecture "x64"

	startproject "Sandbox"

	configurations
	{
	  "Debug",
	  "Release",
	  "Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	IncludeDir = {}
	IncludeDir["GLFW"] = "JumboEngine/vendor/GLFW/include"
	IncludeDir["Glad"] = "JumboEngine/vendor/Glad/include"
	IncludeDir["ImGui"] = "JumboEngine/vendor/imgui"
	IncludeDir["glm"] = "JumboEngine/vendor/glm"


	group "Dependencies"
		include "JumboEngine/vendor/GLFW"
		include "JumboEngine/vendor/Glad"
		include "JumboEngine/vendor/imgui"
	group ""

	project "JumboEngine"
	location "JumboEngine"
	kind "StaticLib"
	language "C++"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "jbpch.h"
	pchsource "%{prj.name}/src/jbpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
   	}

	links
	{
		"Glad",
		"GLFW",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
	
		defines
		{
			"JB_PLATFORM_WINDOWS",
			"JB_BUILD_DLL",
			"GLFW_INCLUDE_NONES"
		}

	filter "configurations:Debug"
		defines "JB_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "JB_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "JB_DIST"
		runtime "Release"
		optimize "on"

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"JumboEngine/vendor/spdlog/include",
			"JumboEngine/src",
			"%{IncludeDir.glm}",
			"%{IncludeDir.ImGui}"
		}

		links
		{
			"JumboEngine"
		}

		filter "system:windows"
			cppdialect "C++17"
			systemversion "latest"

			defines
			{
				"JB_PLATFORM_WINDOWS"
			}

		filter "configurations:Debug"
			defines "JB_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "JB_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "JB_DIST"
			runtime "Release"
			optimize "on"