#include "include/TriangleDemo.h"

VkGen::VkGenerator g_VkGenerator(1280, 720);

int main()
{
	g_VkGenerator.RequireValidation(true);
	g_VkGenerator.LogStateOnInitisation(true);
	g_VkGenerator.LogDeviceInfo(true);

	g_VkGenerator.Init();

	VkTriangleDemo triangle_demo;
	triangle_demo.Setup();
	triangle_demo.Run();
	triangle_demo.Shutdown();

	g_VkGenerator.Destroy();

	return 0;
}
