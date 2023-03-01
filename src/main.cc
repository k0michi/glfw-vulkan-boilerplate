#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

constexpr uint32_t WIDTH = 960;
constexpr uint32_t HEIGHT = 570;
constexpr char APPLICATION_NAME[] = "Vulkan Application";
constexpr char ENGINE_NAME[] = "None";

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  GLFWwindow *window =
      glfwCreateWindow(WIDTH, HEIGHT, APPLICATION_NAME, nullptr, nullptr);

  if (window == nullptr) {
    std::cerr << "glfwCreateWindow() failed" << std::endl;
    return EXIT_FAILURE;
  } else {
    std::cout << "glfwCreateWindow() succeeded" << std::endl;
  }

  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = APPLICATION_NAME;
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = ENGINE_NAME;
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  std::vector<const char *> enabledExtensions = {
      VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME,
      VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME};

  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
  createInfo.pApplicationInfo = &appInfo;
  createInfo.enabledLayerCount = 0;
  createInfo.ppEnabledLayerNames = nullptr;
  createInfo.enabledExtensionCount =
      static_cast<uint32_t>(enabledExtensions.size());
  createInfo.ppEnabledExtensionNames = enabledExtensions.data();

  VkInstance instance;

  if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
    std::cerr << "vkCreateInstance() failed" << std::endl;
    return EXIT_FAILURE;
  } else {
    std::cout << "vkCreateInstance() succeeded" << std::endl;
  }

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

  vkDestroyInstance(instance, nullptr);

  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}