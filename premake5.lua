GameName = "App"

workspace (GameName)
	configurations {
		"Debug",
		"Release"
    }

    platforms {
        "Win64"
    }

    system "windows"
	systemversion "latest"
    architecture "x64"

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
LibraryDir = "%{GameName}/Library"
SourceDir = "Source"

-- Dependency Directiories --
Libraries = {}
Libraries["SFML"] = "%{LibraryDir}/SFML"

project (GameName)
	location (GameName)
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++latest"
	staticruntime "on"

	targetdir ("bin/"..OutputDir.."/%{prj.name}")
	objdir ("bin-int/"..OutputDir.."/%{prj.name}")

    pchheader "pch.h"
    pchsource "%{prj.name}/%{SourceDir}/pch.cpp"

    files {
        "%{prj.name}/%{SourceDir}/**.h",
        "%{prj.name}/%{SourceDir}/**.cpp"
    }

    includedirs {
        "%{prj.name}/%{SourceDir}",
        "%{Libraries.SFML}/include"
	}

	libdirs {
		"%{Libraries.SFML}/lib"
	}

	postbuildcommands {
	    ("{COPY} %{prj.location}Library/SFML/bin/openal32.dll %{wks.location}bin/"..OutputDir.. "/%{GameName}")
	}

	defines {
	    "_CRT_SECURE_NO_WARNINGS",
        "SFML_STATIC"
    }

	links {
        "opengl32.lib",
        "freetype.lib",
        "winmm.lib",
        "gdi32.lib",
        "openal32.lib",
        "flac.lib",
        "vorbisenc.lib",
        "vorbisfile.lib",
        "vorbis.lib",
        "ogg.lib",
	}

	filter "configurations:Debug"
	    buildoptions "/MDd"
		runtime "Debug"
	    symbols "on"

	    defines {
	        "DEBUG",
			"ENABLE_ASSERTS"
		}

	    links {
            "sfml-audio-s-d.lib",
            "sfml-graphics-s-d.lib",
            "sfml-window-s-d.lib",
            "sfml-system-s-d.lib"
	    }

	filter "configurations:Release"
        defines "RELEASE"
        buildoptions "/MD"
        runtime "Release"
        optimize "on"

        links {
            "sfml-audio-s.lib",
            "sfml-graphics-s.lib",
            "sfml-window-s.lib",
            "sfml-system-s.lib"
        }