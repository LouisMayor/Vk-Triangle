#include "include/TriangleDemo.h"

VkGen::VkGenerator VkGenInstance(true, 1280, 720);

int main()
{
	VkGenInstance.LogStateOnInitisation(true);
	VkGenInstance.LogDeviceInfo(true);

	VkGenInstance.Init();

	VkTriangleDemo triangle_demo;

	VkGenInstance.Destroy();

	std::cin.get();

	return 0;
}
