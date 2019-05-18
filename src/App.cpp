#include "include/App.h"

extern VkGen::VkGenerator g_VkGenerator;
extern Logger             g_Logger;

void VkApp::Start()
{
	m_input_manager.InitialiseInput(g_VkGenerator.WindowHdle());
	g_VkGenerator.DisplayWindow(true);

#ifndef NDEBUG
	const HANDLE cmd_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	const int    x          = glfwGetVideoMode(glfwGetPrimaryMonitor())->width;
	SetWindowPos(GetConsoleWindow(), 0, x - 1024, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	g_Logger.Create(cmd_handle);
	g_Logger.Info("Logger Created");
	g_Logger.Info("VkApp::Start() Executed");
#else
	HANDLE cmdHandle = nullptr;
	glfwSetInputMode( windowHandle, GLFW_CURSOR, GLFW_CURSOR_DISABLED );
#endif
}

void VkApp::Update(float _delta)
{
	m_last_delta = _delta;
	m_total_time += _delta;

	UpdateWindowTitle();
}

void VkApp::UpdateWindowTitle()
{
	std::string title = m_window_title + " ||";
	title += " Delta " + std::to_string(m_last_delta);
	title += " FPS " + std::to_string(1.0f / m_last_delta);
	title += " Timer " + std::to_string(m_total_time);

	glfwSetWindowTitle(g_VkGenerator.WindowHdle(), title.c_str());
}

bool VkApp::ShouldStop()
{
	return Input();
}

void VkApp::SetWindowTitle(std::string _title)
{
	m_window_title = _title;
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
	return m_input_manager.KeyHit(EKeyCodes::KeyEsc);
}
