cmake_minimum_required(VERSION 3.16)
project(StreamIt C CXX)

### Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
###

### Platform-specific macros
if(WIN32)
    add_compile_definitions(PLATFORM_WINDOWS)
elseif(UNIX AND NOT APPLE)
    add_compile_definitions(PLATFORM_LINUX)
elseif(APPLE)
    add_compile_definitions(PLATFORM_MACOS)
else()
    message(FATAL_ERROR "Unsupported platform!")
endif()
###

### Use solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
###

### Define directories
set(INCLUDES_DIRECTORY "${PROJECT_SOURCE_DIR}/include")
set(SOURCE_DIRECTORY "${PROJECT_SOURCE_DIR}/src")
set(EXAMPLES_DIRECTORY "${CMAKE_SOURCE_DIR}/examples")
###

### Add include directories
include_directories(${INCLUDES_DIRECTORY})
###

### Collect source files
file(GLOB_RECURSE PROJECT_HEADERS
        "${INCLUDES_DIRECTORY}/*.h"
)

file(GLOB_RECURSE PROJECT_SOURCES
        "${SOURCE_DIRECTORY}/*.c"
        "${SOURCE_DIRECTORY}/*.inl"
)
###

### Create static library
add_library(${PROJECT_NAME} STATIC
        ${PROJECT_HEADERS}
        ${PROJECT_SOURCES}
)
###

### Set include directories for the target
target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${INCLUDES_DIRECTORY}
)
###

### Sub-projects
add_subdirectory(examples/client-win64)
add_subdirectory(examples/server-win64)
###
