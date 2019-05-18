#define GLFW_INCLUDE_VULKAN
#include "glfw3.h"

#include "include/Vk-Generator/VkGenerator.hpp"

int main()
{
	VkGen::VkGenerator VkGenInstance(true, 1280, 720);
	VkGenInstance.LogStateOnInitisation(true);
	VkGenInstance.LogDeviceInfo(true);

	VkGenInstance.Init();

	VkGenInstance.Destroy();

	std::cin.get();

	return 0;
}
