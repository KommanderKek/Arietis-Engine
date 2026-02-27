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
find_package(SDL3 QUIET)
find_package(SDL3_ttf QUIET)

include(FetchContent)

if(NOT SDL3_FOUND)
    message(STATUS "SDL3 not found. Fetching...")
    FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.4.2
    )
    FetchContent_MakeAvailable(SDL3)
endif()

if(NOT SDL3_ttf_FOUND)
    message(STATUS "SDL3_ttf not found. Fetching...")
    FetchContent_Declare(
        SDL3_ttf
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
        GIT_TAG release-3.2.2
    )
    FetchContent_MakeAvailable(SDL3_ttf)
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