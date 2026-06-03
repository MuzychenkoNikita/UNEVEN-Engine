project "Editor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    files { "../Editor/**.hpp", "../Editor/**.cpp", "../Editor/**.h", "../Editor/**.c" }
    includedirs { "../Engine", "../Editor" }

    externalincludedirs { "../Dependencies/include" }

    links { "Engine" }

    targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

    postbuildcommands {
        '{COPYDIR} "../Engine/Renderer/Shaders" "%{cfg.targetdir}"',
        '{COPYFILE} "../Dependencies/lib-arm64/libassimp.6.dylib" "%{cfg.targetdir}/libassimp.6.dylib"'
    }

filter "system:windows"
    systemversion "latest"
    defines { "WINDOWS" }

    libdirs { "../Dependencies/lib" }

    links { 
	    "glfw3",
	    "assimp",
	    "vulkan-1",
	    "slang", 
    }

    postbuildcommands {
        '{COPYDIR} "../Engine/Renderer/Shaders" "%{cfg.targetdir}"',
        '{COPYFILE} "../Dependencies/lib/libassimp-6.dll" "%{cfg.targetdir}/assimp-6.dll"',
        '{COPYFILE} "../Dependencies/lib/vulkan-1.dll" "%{cfg.targetdir}/vulkan-1.dll"',
	'{COPYFILE} "../Dependencies/lib-arm64/libslang-compiler.0.2026.1.dylib" "%{cfg.targetdir}/libslang-compiler.0.2026.1.dylib"',
	'{COPYFILE} "../Dependencies/lib-arm64/libslang-compiler.dylib" "%{cfg.targetdir}/libslang-compiler.dylib"'
    }

filter "system:macosx"
    defines { "MACOS" }
    architecture "ARM64"
    system "macosx"

    libdirs { "../Dependencies/lib-arm64" }

    links {
        "glfw3",
        "assimp",
        "vulkan",
	"slang", 
        "Cocoa.framework",
        "IOKit.framework",
        "CoreVideo.framework",
        "CoreFoundation.framework",
        "QuartzCore.framework",
        "Metal.framework"
    }

    linkoptions {
        "-Wl,-rpath,@executable_path",
        "-Wl,-rpath,@loader_path",
        "-Wl,-rpath,@executable_path/../../../Dependencies/lib-arm64",
        "-Wl,-rpath,@loader_path/../../../Dependencies/lib-arm64"
    }

    postbuildcommands {
        '{COPYDIR} "../Engine/Renderer/Shaders" "%{cfg.targetdir}"',
        '{COPYFILE} "../Dependencies/lib-arm64/libassimp.6.dylib" "%{cfg.targetdir}/libassimp.6.dylib"',
        '{COPYFILE} "../Dependencies/lib-arm64/libglfw.3.dylib" "%{cfg.targetdir}/libglfw.3.dylib"',
        '{COPYFILE} "../Dependencies/lib-arm64/libvulkan.dylib" "%{cfg.targetdir}/libvulkan.dylib"',
        '{COPYFILE} "../Dependencies/lib-arm64/libvulkan.1.dylib" "%{cfg.targetdir}/libvulkan.1.dylib"',
        '{COPYFILE} "../Dependencies/lib-arm64/libvulkan.1.4.341.dylib" "%{cfg.targetdir}/libvulkan.1.4.341.dylib"',
        '{COPYFILE} "../Dependencies/lib-arm64/libMoltenVK.dylib" "%{cfg.targetdir}/libMoltenVK.dylib"',
	'{COPYFILE} "../Dependencies/lib-arm64/libslang-compiler.0.2026.1.dylib" "%{cfg.targetdir}/libslang-compiler.0.2026.1.dylib"',
	'{COPYFILE} "../Dependencies/lib-arm64/libslang-compiler.dylib" "%{cfg.targetdir}/libslang-compiler.dylib"'
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