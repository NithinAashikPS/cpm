if (WIN32)
    set(URL "https://github.com/git-for-windows/git/releases/download/v2.45.2.windows.1/Git-2.45.2-${ARCHITECTURE}.tar.bz2")
    set(OUTPUT_FILE "${CMAKE_BINARY_DIR}/git.bz2")
    if(NOT EXISTS ${OUTPUT_FILE})
        message(STATUS "Downloading Git-2.45.2-${ARCHITECTURE}.tar.bz2")
        file(DOWNLOAD ${URL} ${OUTPUT_FILE} SHOW_PROGRESS)
    endif()
    message(STATUS "Extracting Git-2.45.2-${ARCHITECTURE}.tar.bz2")
    execute_process(
            COMMAND "${WIN_RAR_DIRECTORY}\\WinRAR.exe" x "git.bz2"
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "git extraction failed")
    endif()
    install(FILES ${CMAKE_BINARY_DIR}/git DESTINATION bin/)
endif (WIN32)