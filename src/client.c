//
// Created by Riley on 4/08/2022.
//

#include "client.h"

VkApplicationInfo cl_appInfo;

int cl_init()
{
    if (!glfwInit())
        return -1;

    cl_appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    cl_appInfo.pApplicationName = "Hello Triangle";
    cl_appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    cl_appInfo.pEngineName = "No Engine";
    cl_appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    cl_appInfo.apiVersion = VK_API_VERSION_1_0;

    //INIT
}