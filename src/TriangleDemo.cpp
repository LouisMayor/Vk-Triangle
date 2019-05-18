#include "include/TriangleDemo.h"

Logger g_Logger;

void VkTriangleDemo::Setup()
{
	CreateSwapchain();
	CreateImageViews();
	CreateCmdPool();
	CreateColourResources();
	CreateDepthResources();
	CreateRenderPasses();
	CreateFrameBuffers();
	CreatePipelines();
	RecordCmdBuffer();

	m_app_instance.Start();
}

void VkTriangleDemo::Run()
{
	float initTime      = 0.0f;
	bool  stopExecution = false;

	while (!stopExecution)
	{
		const float total_time = static_cast<float>(glfwGetTime());
		const float delta      = total_time - initTime;
		initTime               = total_time;

		m_app_instance.Update(delta);
		stopExecution = m_app_instance.ShouldStop();

		SubmitQueue();
	}
}

void VkTriangleDemo::Shutdown()
{
	m_app_instance.Close();
}

void VkTriangleDemo::SubmitQueue()
{}

void VkTriangleDemo::RecordCmdBuffer()
{}

void VkTriangleDemo::CreateSwapchain()
{}

void VkTriangleDemo::CreateImageViews()
{}

void VkTriangleDemo::CreateCmdPool()
{}

void VkTriangleDemo::CreateRenderPasses()
{}

void VkTriangleDemo::CreateFrameBuffers()
{}

void VkTriangleDemo::CreatePipelines()
{}

void VkTriangleDemo::CreateColourResources()
{}

void VkTriangleDemo::CreateDepthResources()
{}
