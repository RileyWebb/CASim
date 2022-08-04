cmake_minimum_required(VERSION 3.21)
project(CASim C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(ext)

# Game of Life
add_executable(CASim src/main.c src/instance.c src/cl_window.c include/casim.h include/client.h src/client.c include/renderer.h include/compute.h)

target_link_libraries(
        CASim

        glfw
        cimgui
        ${Vulkan_LIBRARIES}
        ${EXTRA_LIBS}
)