project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	targetdir "Binaries/%{cfg.buildcfg}"
	staticruntime "off"

files { "../Engine/**.hpp", "../Engine/**.cpp", "../Engine/**.h", "../Engine/**.c", "../Engine/**.vs", "../Engine/**.fs" }

includedirs { "../Engine" }
   
externalincludedirs { "../Dependencies/include" }

targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

postbuildcommands {
    '{COPYDIR} "../Engine/Renderer/Shaders" "%{cfg.targetdir}"',
    '{COPYFILE} "../Dependencies/lib-arm64/libassimp.6.dylib" "%{cfg.targetdir}/libassimp.6.dylib"'
}

filter "system:windows"
       systemversion "latest"
       defines {}
       libdirs { "../Dependencies/lib" }
       links   { "glfw3" }
       
filter "system:macosx"
       defines { "MACOS" }
       architecture "ARM64"
       system "macosx"
       libdirs { "../Dependencies/lib-arm64" }
	links   {  
        "glfw3",
        "OpenGL.framework",
        "Cocoa.framework",
        "IOKit.framework",
        "CoreVideo.framework",
        "CoreFoundation.framework",
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