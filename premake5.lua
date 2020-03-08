
workspace "Je"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

    project "Je.Engine"
        location "Je.Engine"
        kind "SharedLib"
        language "C++"

        targetdir ("bin/" .. outputdir)
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "dependencies/GLEW/include"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines
            {
                "JE_PLATFORM_WIN",
                "JE_BUILD"
            }

        filter "configurations:Debug"
            defines "DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "RELEASE"
            optimize "On"

    project "Je.Playground"
        location "Je.Playground"
        kind "ConsoleApp"
        language "C++"

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
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines
            {
                "JE_PLATFORM_WIN"
            }

        filter "configurations:Debug"
            defines "DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "RELEASE"
            optimize "On"