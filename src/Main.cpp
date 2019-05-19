#include "include/TriangleDemo.h"

VkGen::VkGenerator g_VkGenerator(1280, 720);
Logger             g_Logger;

int main()
{
#ifndef NDEBUG
	const HANDLE cmd_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	g_Logger.Create(cmd_handle);
	g_Logger.Info("Logger Created");
#endif

	g_VkGenerator.RequireValidation(true);
	g_VkGenerator.LogStateOnInitisation(true);
	g_VkGenerator.LogDeviceInfo(true);

	VkTriangleDemo triangle_demo;
	g_VkGenerator.AddValidationLayerCallback(triangle_demo.TriangleDemoDebugCallback);

	g_VkGenerator.Init();

	triangle_demo.Setup();
	triangle_demo.Run();
	triangle_demo.Shutdown();

	g_VkGenerator.Destroy();

	return 0;
}
