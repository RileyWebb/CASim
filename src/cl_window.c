//
// Created by Riley on 4/08/2022.
//

#include "client.h"

cl_window *cl_createWindow()
{
    cl_window win = {};

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    win.glfwWindow = glfwCreateWindow(1000, 1000, "Test", NULL, NULL);

    printf(cl_appInfo.pApplicationName);

    return &win;
}

void cl_updateWindow(cl_window* window)
{

}