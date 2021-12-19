workspace "AuxoEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}"

project "Auxo"
    location "Auxo"
    kind "SharedLib"
    language "c++"

    targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "Auxo/Source/"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "10.0.22000.0"

        defines
        {
            "AUXO_BUILD",
        }

        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} ../Binaries/" .. outputdir .. "/SandBox/"
        }

        filter "configurations:Debug"
            defines "AUXO_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "AUXO_RELEASE"
            symbols "On"

        filter "configurations:Dist"
            defines "AUXO_DIST"
            symbols "On"

project "SandBox"
    location "SandBox"
    kind "ConsoleApp"

    targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "Auxo/Source/"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "10.0.22000.0"

        defines
        {

        }

        links
        {
            "Auxo"
        }

        filter "configurations:Debug"
            defines "AUXO_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "AUXO_RELEASE"
            symbols "On"

        filter "configurations:Dist"
            defines "AUXO_DIST"
            symbols "On"