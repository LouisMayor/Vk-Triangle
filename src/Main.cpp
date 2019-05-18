#include "include/TriangleDemo.h"

VkGen::VkGenerator VkGenInstance(true, 1280, 720);

int main()
{
	VkGenInstance.LogStateOnInitisation(true);
	VkGenInstance.LogDeviceInfo(true);

	VkGenInstance.Init();

	VkTriangleDemo triangle_demo;
	triangle_demo.Setup();
	triangle_demo.Run();
	triangle_demo.Shutdown();

	VkGenInstance.Destroy();

	return 0;
}
