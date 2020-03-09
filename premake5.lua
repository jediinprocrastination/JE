
workspace "Je"
    architecture "x64"
    
    architectureCode = "x64"
    outputdir = "%{cfg.buildcfg}-%{architectureCode}"
    outputpath = ("bin/" .. outputdir)

    glewdir = "dependencies/GLEW/"

    configurations
    {
        "Debug",
        "Release"
    }

    startproject "Je.Playground"

    project "Je.Engine"
        location "Je.Engine"
        kind "SharedLib"
        language "C++"
        cppdialect "C++17"
        staticruntime "On"

        targetdir "%{outputpath}"
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        pchheader "Jepch.h"
        pchsource "Je.Engine/src/Jepch.cpp"

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "%{glewdir}include",
            "%{prj.name}/src",
            "%{prj.name}/vendor/spdlog/include"
        }

        filter "system:windows"
            systemversion "latest"

            defines
            {
                "JE_PLATFORM_WIN",
                "JE_BUILD"
            }

            links
            {
                "Gdi32.lib",
                "Opengl32.lib",
                "User32.lib",
                "%{wks.location}/%{glewdir}lib/glew32.lib"
            }

            postbuildcommands
            {
                ("{COPY} %{wks.location}%{glewdir}/bin/glew32.dll %{wks.location}%{outputpath}")
            }

        filter "configurations:Debug"
            defines "DEBUG"
            buildoptions "/MDd"
            symbols "On"

        filter "configurations:Release"
            defines "RELEASE"
            buildoptions "/MD"
            optimize "On"

    project "Je.Playground"
        location "Je.Playground"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        staticruntime "On"

        targetdir ("bin/" .. outputdir)
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "Je.Engine/src"
        }

        links
        {
            "Je.Engine"
        }

        filter "system:windows"
            systemversion "latest"

            defines
            {
                "JE_PLATFORM_WIN"
            }

        filter "configurations:Debug"
            defines "DEBUG"
            buildoptions "/MDd"
            symbols "On"

        filter "configurations:Release"
            defines "RELEASE"
            buildoptions "/MD"
            optimize "On"