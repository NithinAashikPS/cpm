string(TOLOWER "${CMAKE_SYSTEM_NAME}" SYSTEM_NAME)
string(TOLOWER "${ARCH}" SYSTEM_PROCESSOR)

if (WIN32)
    set(URL "https://github.com/Kitware/CMake/releases/download/v3.30.1/cmake-3.30.1-${SYSTEM_NAME}-${SYSTEM_PROCESSOR}.zip")
    set(OUTPUT_FILE "${CMAKE_BINARY_DIR}/cmake.zip")
    if(NOT EXISTS ${OUTPUT_FILE})
        message(STATUS "Downloading cmake-3.30.1-${SYSTEM_NAME}-${SYSTEM_PROCESSOR}.zip")
        file(DOWNLOAD ${URL} ${OUTPUT_FILE} SHOW_PROGRESS)
    endif()
    message(STATUS "Extracting cmake-3.30.1-${SYSTEM_NAME}-${SYSTEM_PROCESSOR}.zip")
    execute_process(
            COMMAND "${WIN_RAR_DIRECTORY}\\WinRAR.exe" x "cmake.zip"
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "cmake extraction failed")
    endif()
    install(DIRECTORY "${CMAKE_BINARY_DIR}/cmake-3.30.1-${SYSTEM_NAME}-${SYSTEM_PROCESSOR}/" DESTINATION "/"  PATTERN "doc" EXCLUDE)
endif (WIN32)
