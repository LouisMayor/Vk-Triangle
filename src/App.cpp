#include "include/App.h"

extern VkGen::VkGenerator g_VkGenerator;
extern Logger             g_Logger;

void VkApp::Start()
{
	m_input_manager.InitialiseInput(g_VkGenerator.WindowHdle());
	g_VkGenerator.DisplayWindow(true);

#ifndef NDEBUG
	HANDLE cmdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int    x         = glfwGetVideoMode(glfwGetPrimaryMonitor())->width;
	SetWindowPos(GetConsoleWindow(), 0, x - 1024, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	g_Logger.Create(cmdHandle);
	g_Logger.Info("Logger Created");
	g_Logger.Info("VkApp::Start() Executed");
#else
	HANDLE cmdHandle = nullptr;
	glfwSetInputMode( windowHandle, GLFW_CURSOR, GLFW_CURSOR_DISABLED );
#endif
}

void VkApp::Update(float _delta)
{
	m_total_time += _delta;
}

bool VkApp::ShouldStop()
{
	return Input();
}

void VkApp::Close()
{
#ifndef NDEBUG
	g_Logger.Info("VkApp::Close() Executed");
#endif

	glfwDestroyWindow(g_VkGenerator.WindowHdle());
	glfwTerminate();
}

bool VkApp::Input()
{
	glfwPollEvents();
	return m_input_manager.KeyHit(eKeyCodes::KeyEsc);
}
