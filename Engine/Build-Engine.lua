project "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    files { "../Engine/**.hpp", "../Engine/**.cpp", "../Engine/**.h", "../Engine/**.c",
            "../Engine/**.vs", "../Engine/**.fs" }

    includedirs { "../Engine" }
    externalincludedirs { "../Dependencies/include" }

    targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

filter "system:windows"
    systemversion "latest"
    defines { "WINDOWS" }

    libdirs { "../Dependencies/lib" }
    links { "glfw3", "vulkan-1" }

filter "system:macosx"
    defines { "MACOS" }
    architecture "ARM64"
    system "macosx"

    libdirs { "../Dependencies/lib-arm64" }

    links {
    }

    linkoptions {
        "-Wl,-rpath,@executable_path",
        "-Wl,-rpath,@loader_path",
        "-Wl,-rpath,@executable_path/../Engine",
        "-Wl,-rpath,@loader_path/../Engine",
        "-Wl,-rpath,@executable_path/../../../Dependencies/lib-arm64",
        "-Wl,-rpath,@loader_path/../../../Dependencies/lib-arm64"
    }

    postbuildcommands {
        '{COPYFILE} "../Dependencies/lib-arm64/libvulkan.dylib" "%{cfg.targetdir}/libvulkan.dylib"',
        '{COPYFILE} "../Dependencies/lib-arm64/libvulkan.1.dylib" "%{cfg.targetdir}/libvulkan.1.dylib"',
        '{COPYFILE} "../Dependencies/lib-arm64/libvulkan.1.4.341.dylib" "%{cfg.targetdir}/libvulkan.1.4.341.dylib"',
        '{COPYFILE} "../Dependencies/lib-arm64/libMoltenVK.dylib" "%{cfg.targetdir}/libMoltenVK.dylib"',
        '{COPYFILE} "../Dependencies/lib-arm64/libglfw.3.dylib" "%{cfg.targetdir}/libglfw.3.dylib"'
    }

filter {}

filter "configurations:Debug"
    defines { "DEBUG" }
    runtime "Debug"
    symbols "On"

filter "configurations:Release"
    defines { "RELEASE" }
    runtime "Release"
    optimize "On"
    symbols "On"

filter "configurations:Dist"
    defines { "DIST" }
    runtime "Release"
    optimize "On"
    symbols "Off"