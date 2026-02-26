project "Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	targetdir "Binaries/%{cfg.buildcfg}"
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
       links   { "glfw3", "assimp" }
       
filter "system:macosx"
        defines { "MACOS" }
        architecture "ARM64"
        system "macosx"
	libdirs { "../Dependencies/lib-arm64" }
	links   {  
        "glfw3",
	"assimp",
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