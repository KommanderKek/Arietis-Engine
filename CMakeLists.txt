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

# Link SDL
add_subdirectory(external/SDL3)
target_link_libraries(Arietis PRIVATE SDL3::SDL3)

# Copy SDL3.dll to executable folder
add_custom_command(TARGET Arietis POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3>
        $<TARGET_FILE_DIR:Arietis>
)

# Copy sample.bmp to the executable folder
add_custom_command(TARGET Arietis POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/assets/sample.bmp"
        $<TARGET_FILE_DIR:Arietis>
)