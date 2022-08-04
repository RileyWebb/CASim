//
// Created by Riley on 4/08/2022.
//

#ifndef CASIM_CLIENT_H
#define CASIM_CLIENT_H

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "casim.h"

extern VkApplicationInfo cl_appInfo;

typedef struct
{
    GLFWwindow *glfwWindow;
    GLFWmonitor *glfwMonitor;
} cl_window;

typedef struct
{


    cl_window* window;
    VkInstance instance;
} c_instance;

int cl_init();
cl_window *cl_createWindow();

#endif //CASIM_CLIENT_H
