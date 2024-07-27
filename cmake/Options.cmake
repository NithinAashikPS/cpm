if (WIN32)
    set(WIN_RAR_DIRECTORY "$ENV{PROGRAMFILES}\\WinRar" CACHE PATH "Path to WinRar directory")

    if(NOT EXISTS "${WIN_RAR_DIRECTORY}\\WinRAR.exe")
        message(FATAL_ERROR "WinRAR.exe not found in ${WIN_RAR_DIRECTORY}")
    endif()
endif (WIN32)