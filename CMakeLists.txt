cmake_minimum_required(VERSION 3.28)
project(cpm)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PACKAGE_DIR ${CMAKE_SOURCE_DIR}/cmake/package)

set(
        PROJECT_HEADERS
        ${INCLUDE_DIR}/main.hpp

        ${INCLUDE_DIR}/commands/command.hpp
        ${INCLUDE_DIR}/commands/init.hpp

        ${INCLUDE_DIR}/core/application.hpp

        ${INCLUDE_DIR}/utils/file.hpp
        ${INCLUDE_DIR}/utils/console.hpp
)

set(
        PROJECT_SOURCES
        ${CMAKE_SOURCE_DIR}/src/main.cpp

        ${CMAKE_SOURCE_DIR}/src/commands/init.cpp

        ${CMAKE_SOURCE_DIR}/src/core/application.cpp

        ${CMAKE_SOURCE_DIR}/src/utils/file.cpp
        ${CMAKE_SOURCE_DIR}/src/utils/console.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

include(${PACKAGE_DIR}/Package.cmake)
