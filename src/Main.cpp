#include "include/TriangleDemo.h"

VkGen::VkGenerator g_VkGenerator(1280, 720);
Logger             g_Logger;

int main()
{
#ifdef _DEBUG
	const HANDLE cmd_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	g_Logger.Create(cmd_handle);
	g_Logger.Info("Logger Created");
	g_VkGenerator.RequireValidation(true);
	g_VkGenerator.AddValidationLayerCallback(VkTriangleDemo::TriangleDemoDebugCallback);
#endif

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
