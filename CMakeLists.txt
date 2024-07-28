cmake_minimum_required(VERSION 3.28)
project(cpm VERSION 1.0.0)

include(${CMAKE_SOURCE_DIR}/cmake/Arch.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/Options.cmake)

detect_and_set_architecture()

set(CMAKE_CXX_STANDARD 20)
#Un comment for custom Installer.
#set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/resources/nsis ${CMAKE_MODULE_PATH})

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PACKAGE_DIR ${CMAKE_SOURCE_DIR}/cmake/package)
set(DOWNLOAD_DIR ${CMAKE_SOURCE_DIR}/cmake/download)

set(
        PROJECT_HEADERS
        ${INCLUDE_DIR}/main.hpp

        ${INCLUDE_DIR}/commands/command.hpp
        ${INCLUDE_DIR}/commands/init.hpp

        ${INCLUDE_DIR}/core/application.hpp

        ${INCLUDE_DIR}/core/vcpkg/vcpkg.hpp

        ${INCLUDE_DIR}/core/service/service.hpp
        ${INCLUDE_DIR}/core/service/vcpkg.hpp

        ${INCLUDE_DIR}/core/impl/vcpkg.hpp

        ${INCLUDE_DIR}/core/actor/actor.hpp
        ${INCLUDE_DIR}/core/actor/async_actor.hpp
        ${INCLUDE_DIR}/core/actor/message.hpp
        ${INCLUDE_DIR}/core/actor/message_interface.hpp

        ${INCLUDE_DIR}/utils/file.hpp
        ${INCLUDE_DIR}/utils/console.hpp
)

set(
        PROJECT_SOURCES
        ${CMAKE_SOURCE_DIR}/src/main.cpp

        ${CMAKE_SOURCE_DIR}/src/commands/init.cpp

        ${CMAKE_SOURCE_DIR}/src/core/application.cpp

        ${CMAKE_SOURCE_DIR}/src/core/vcpkg/vcpkg.cpp

        ${CMAKE_SOURCE_DIR}/src/core/service/vcpkg.cpp

        ${CMAKE_SOURCE_DIR}/src/utils/file.cpp
        ${CMAKE_SOURCE_DIR}/src/utils/console.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

include(CPack)
include(${PACKAGE_DIR}/Package.cmake)
include(${DOWNLOAD_DIR}/Download.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/cpack/${CMAKE_SYSTEM_NAME}.cmake)
