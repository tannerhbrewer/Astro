workspace "Astro"
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
IncludeDir["GLFW"] = "Astro/vendor/GLFW/include"
IncludeDir["Glad"] = "Astro/vendor/Glad/include"
IncludeDir["ImGui"] = "Astro/vendor/imgui"
IncludeDir["glm"] = "Astro/vendor/glm"

group "Dependencies"
	include "Astro/vendor/GLFW"
	include "Astro/vendor/Glad"
	include "Astro/vendor/imgui"
group ""

project "Astro"
	location "Astro"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "aspch.h"
	pchsource "%{prj.name}/src/aspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AS_PLATFORM_WINDOWS",
			"AS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "AS_DEBUG"
		buildoptions "/MDd"

	filter "configurations:Release"
		defines "AS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AS_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Astro/vendor/spdlog/include",
		"Astro/src",
		"Astro/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Astro"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AS_DEBUG"
		buildoptions "/MDd"

	filter "configurations:Release"
		defines "AS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AS_DIST"
		runtime "Release"
		optimize "on"