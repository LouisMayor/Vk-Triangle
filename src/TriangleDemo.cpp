#include "include/TriangleDemo.h"

Logger g_Logger;

void VkTriangleDemo::Setup()
{
	m_app_instance.Start();
}

void VkTriangleDemo::Run()
{
	bool stopExecution = false;
	while (!stopExecution)
	{
		m_app_instance.Update();
		stopExecution = m_app_instance.ShouldStop();
	}
}

void VkTriangleDemo::Shutdown()
{
	m_app_instance.Close();
}
