#include "include/App.h"

extern VkGen::VkGenerator g_VkGenerator;

void VkApp::Start()
{
	m_input_manager.InitialiseInput(g_VkGenerator.WindowHdle());
	g_VkGenerator.DisplayWindow(true);
}

void VkApp::Update()
{}

bool VkApp::ShouldStop()
{
	return Input();
}

void VkApp::Close()
{
	glfwDestroyWindow(g_VkGenerator.WindowHdle());
	glfwTerminate();
}

bool VkApp::Input()
{
	glfwPollEvents();
	return m_input_manager.KeyHit(eKeyCodes::KeyEsc);
}
