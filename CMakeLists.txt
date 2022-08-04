cmake_minimum_required(VERSION 3.21)
project(CASim C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# GLFW
option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)

add_subdirectory(ext/GLFW)

# Vulkan
find_package(Vulkan REQUIRED)

include_directories(${Vulkan_INCLUDE_DIRS})
include_directories(include)

# Game of Life
add_executable(CASim src/main.c src/instance.c src/cl_window.c include/casim.h include/client.h src/client.c include/renderer.h include/compute.h)

target_link_libraries(
        CASim

        glfw
        ${Vulkan_LIBRARIES}
        ${EXTRA_LIBS}
)