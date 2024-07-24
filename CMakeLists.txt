cmake_minimum_required(VERSION 3.28)
project(cpm)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PACKAGE_DIR ${CMAKE_SOURCE_DIR}/cmake/package)

set(
        PROJECT_HEADERS
        ${INCLUDE_DIR}/main.hpp
)

set(
        PROJECT_SOURCES
        ${CMAKE_SOURCE_DIR}/src/main.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

include(${PACKAGE_DIR}/Package.cmake)
