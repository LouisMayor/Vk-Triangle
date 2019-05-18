#include "include/TriangleDemo.h"

extern VkGen::VkGenerator g_VkGenerator;
Logger                    g_Logger;

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

	m_app_instance.SetWindowTitle("Vulkan Triangle Demo");
	m_app_instance.Start();
}

void VkTriangleDemo::Run()
{
	float init_time      = 0.0f;
	bool  stop_execution = false;

	while (!stop_execution || !glfwWindowShouldClose(g_VkGenerator.WindowHdle()))
	{
		const float total_time = static_cast<float>(glfwGetTime());
		const float delta      = total_time - init_time;
		init_time              = total_time;

		m_app_instance.Update(delta);
		stop_execution = m_app_instance.ShouldStop();

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
