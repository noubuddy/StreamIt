cmake_minimum_required(VERSION 3.31.0 FATAL_ERROR)

project(StreamIt C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Platform-specific macros
if(WIN32)
    add_compile_definitions(PLATFORM_WINDOWS)
elseif(UNIX AND NOT APPLE)
    add_compile_definitions(PLATFORM_LINUX)
elseif(APPLE)
    add_compile_definitions(PLATFORM_MACOS)
else()
    message(FATAL_ERROR "Unsupported platform!")
endif()

# Define configuration types
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Development" CACHE STRING "" FORCE)

# Define architecture and set default if not provided
if(NOT CMAKE_VS_PLATFORM_NAME)
    set(CMAKE_VS_PLATFORM_NAME "x64")
endif()
message(STATUS "${CMAKE_VS_PLATFORM_NAME} architecture in use")

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64" OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86"))
    message(FATAL_ERROR "${CMAKE_VS_PLATFORM_NAME} architecture is not supported!")
endif()

# Source directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(EXAMPLES_DIR "${CMAKE_SOURCE_DIR}/examples")

# Configure a static library
file(GLOB_RECURSE LIBRARY_SOURCES "${SRC_DIR}/*.c" "${SRC_DIR}/*.h")
add_library(StreamItLib STATIC ${LIBRARY_SOURCES})
source_group(TREE ${SRC_DIR} PREFIX "StreamItLib" FILES ${LIBRARY_SOURCES})

# Configure example projects
set(CLIENT_MAIN "${EXAMPLES_DIR}/client-win64/main.c")
set(SERVER_MAIN "${EXAMPLES_DIR}/server-win64/main.c")

if(EXISTS ${CLIENT_MAIN})
    file(GLOB_RECURSE CLIENT_SOURCES "${EXAMPLES_DIR}/client-win64/*.c" "${EXAMPLES_DIR}/client-win64/*.h")
    add_executable(ClientWin64 ${CLIENT_MAIN} ${CLIENT_SOURCES})
    target_link_libraries(ClientWin64 PRIVATE StreamItLib)
    set_target_properties(ClientWin64 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/client"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/client/Debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/client/Release"
        VS_DEBUGGER_WORKING_DIRECTORY "${EXAMPLES_DIR}/client-win64"
    )
    source_group(TREE ${EXAMPLES_DIR}/client-win64 PREFIX "Client-Win64" FILES ${CLIENT_SOURCES})
endif()

if(EXISTS ${SERVER_MAIN})
    file(GLOB_RECURSE SERVER_SOURCES "${EXAMPLES_DIR}/server-win64/*.c" "${EXAMPLES_DIR}/server-win64/*.h")
    add_executable(ServerWin64 ${SERVER_MAIN} ${SERVER_SOURCES})
    target_link_libraries(ServerWin64 PRIVATE StreamItLib)
    set_target_properties(ServerWin64 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/server"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/server/Debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/server/Release"
        VS_DEBUGGER_WORKING_DIRECTORY "${EXAMPLES_DIR}/server-win64"
    )
    source_group(TREE ${EXAMPLES_DIR}/server-win64 PREFIX "Server-Win64" FILES ${SERVER_SOURCES})
endif()

# Use solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
