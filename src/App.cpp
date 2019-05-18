#include "include/App.h"

void VkApp::Start()
{
	m_input_manger.InitialiseInput();
}

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
	return m_input_manger.KeyHit(eKeyCodes::KeyEsc);
}
