#include "include/App.h"

void VkApp::Start()
{}

void VkApp::Update()
{
	ShouldStop();
}

bool VkApp::ShouldStop()
{
	return !Input();
}

void VkApp::Close()
{}

bool VkApp::Input()
{
	m_input_manger.InitialiseInput();

	return false;
}
