cmake_minimum_required(VERSION 3.21)
project(ArietisEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
    src/*.h
    src/*.cpp
)
add_executable(arietis ${SOURCES})

# Relative path to SDL3 folder
set(SDL3_DIR "${CMAKE_SOURCE_DIR}/external/SDL3-3.4.0")

# Set SDL3 include directory and link SDL3 library
target_include_directories(arietis PRIVATE "${SDL3_DIR}/include")
target_link_libraries(arietis PRIVATE "${SDL3_DIR}/lib/x64/SDL3.lib")

# Copy SDL3.dll to executable folder
add_custom_command(TARGET arietis POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL3_DIR}/lib/x64/SDL3.dll"
        $<TARGET_FILE_DIR:arietis>
)

# Copy sample.bmp to the executable folder
add_custom_command(TARGET arietis POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/assets/sample.bmp"
        $<TARGET_FILE_DIR:arietis>
)