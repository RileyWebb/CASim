cmake_minimum_required(VERSION 3.21)

# GLFW
option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)

add_subdirectory(GLFW)

#cImGui
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(cImGui)
include_directories(cImGui/imgui)
include_directories(cImGui/generator/output/)

set(IMGUI_STATIC  ON)

if (WIN32)
    add_definitions("-DIMGUI_IMPL_API=extern \"C\" __declspec\(dllexport\)")
else(WIN32)
    add_definitions("-DIMGUI_IMPL_API=extern \"C\" ")
endif(WIN32)

set(IMGUI_SOURCES cImGui/cimgui.cpp
        cImGui/imgui/imgui.cpp
        cImGui/imgui/imgui_draw.cpp
        cImGui/imgui/imgui_demo.cpp
        cImGui/imgui/imgui_widgets.cpp
        cImGui/imgui/imgui_tables.cpp
        ${TABLES_SOURCE}
        )

add_library(cimgui STATIC ${IMGUI_SOURCES})

target_link_libraries(cimgui ${IMGUI_LIBRARIES})
target_compile_definitions(cimgui PUBLIC -DCIMGUI_USE_VULKAN -DCIMGUI_USE_GLFW -DIMGUI_DISABLE_OBSOLETE_FUNCTIONS=1)

# Vulkan
find_package(Vulkan REQUIRED)

include_directories(${Vulkan_INCLUDE_DIRS})
include_directories(../include)