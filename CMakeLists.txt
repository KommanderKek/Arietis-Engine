cmake_minimum_required(VERSION 3.20)
project(ArietisEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find all source files
file(GLOB_RECURSE SOURCES
    src/*.h
    src/*.cpp
)

# Add runnable executable
add_executable(Arietis ${SOURCES})

# Add include directories for header files
target_include_directories(Arietis PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Building and linking SDL
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/deps")

find_package(SDL3 QUIET)
find_package(SDL3_ttf QUIET)

include(ExternalProject)

if(NOT SDL3_FOUND)
    message(STATUS "SDL3 not found. Building from source...")

    ExternalProject_Add(SDL3_project
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/SDL-3.4.2
        BINARY_DIR ${CMAKE_BINARY_DIR}/SDL3_build
        CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/deps
            -DSDL_TEST=OFF
    )

    add_subdirectory(external/SDL-3.4.2)
endif()

if(NOT SDL3_ttf_FOUND AND SDL3_FOUND)
    message(STATUS "SDL3_ttf not found. Building from source...")

    find_package(Python3 REQUIRED COMPONENTS Interpreter)

    ExternalProject_Add(SDL3_ttf_project
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/SDL_ttf-3.2.2
        BINARY_DIR ${CMAKE_BINARY_DIR}/SDL3_ttf_build
        CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/deps
            -DCMAKE_PREFIX_PATH=${CMAKE_SOURCE_DIR}/deps
            -DPython3_EXECUTABLE=${Python3_EXECUTABLE}
    )
endif()

if(NOT SDL3_ttf_FOUND)
    add_subdirectory(external/SDL_ttf-3.2.2)
endif()

target_link_libraries(Arietis
    PRIVATE
    SDL3::SDL3
    SDL3_ttf::SDL3_ttf
)

# Copy SDL3.dll and SDL_ttf.dll to executable folder
add_custom_command(TARGET Arietis POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3>
        $<TARGET_FILE_DIR:Arietis>
)
add_custom_command(TARGET Arietis POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3_ttf::SDL3_ttf>
        $<TARGET_FILE_DIR:Arietis>
)

# Copy sample.bmp to the executable folder
add_custom_command(TARGET Arietis POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/assets/sample.bmp"
        $<TARGET_FILE_DIR:Arietis>
)