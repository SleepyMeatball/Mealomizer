workspace "MealRandomizer"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }
    platforms "Win64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MealRandomizer"
    location "MealRandomizer"
    kind "ConsoleApp"
    language "C++"

    targetname "Mealomizer"
    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir)

    pchheader "pch.h"
    pchsource "MealRandomizer/src/pch.cpp"

    includedirs {
        "%{prj.name}/src/**"
    }

    files {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h"
    }

    filter "system:windows"
        cppdialect "C++latest"
        systemversion "latest"

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

    filter "platforms:Win64"
        defines "PLATFORM_WIN64"