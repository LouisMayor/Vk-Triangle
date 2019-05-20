#include "include/TriangleDemo.h"

extern VkGen::VkGenerator g_VkGenerator;
extern Logger             g_Logger;

void VkTriangleDemo::Setup()
{
	CreateSwapchain();
	CreateCmdPool();
	CreateColourResources();
	CreateDepthResources(); // Not created for this program
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

	while (!stop_execution)
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
	m_graphics_pipeline.Destroy(g_VkGenerator.Device());

	for (auto& i : m_framebuffers)
	{
		i.Destroy(g_VkGenerator.Device());
	}

	m_render_pass.Destroy(g_VkGenerator.Device());
	m_backbuffer.Destroy(g_VkGenerator.Device());
	m_command.Destroy(g_VkGenerator.Device());
	m_swapchain.Destroy(g_VkGenerator.Device());

	m_app_instance.Close();
}

VkBool32 VkTriangleDemo::TriangleDemoDebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT      _message_severity,
                                                   VkDebugUtilsMessageTypeFlagsEXT             _message_type,
                                                   const VkDebugUtilsMessengerCallbackDataEXT* _p_callback_data,
                                                   void*                                       _p_user_data)
{
	std::string message = "validation layer: ";
	if (_message_severity == VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT)
	{
		g_Logger.Error(message + _p_callback_data->pMessage);
	}
	else if (_message_severity == VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
	{
		g_Logger.Warning(message + _p_callback_data->pMessage);
	}
	else
	{
		g_Logger.Info(message + _p_callback_data->pMessage);
	}
	return VK_FALSE;
}

void VkTriangleDemo::SubmitQueue()
{}

void VkTriangleDemo::RecordCmdBuffer()
{}

void VkTriangleDemo::CreateSwapchain()
{
	m_swapchain = VkRes::Swapchain(g_VkGenerator.PhysicalDevice(), g_VkGenerator.Device(), g_VkGenerator.Surface(),
	                               g_VkGenerator.SwapchainDetails(), g_VkGenerator.QueueFamily());
}

void VkTriangleDemo::CreateCmdPool()
{
	m_command = VkRes::Command(g_VkGenerator.Device(), g_VkGenerator.QueueFamily());
}

void VkTriangleDemo::CreateRenderPasses()
{
	vk::AttachmentReference colour_attachment =
	{
		0,
		vk::ImageLayout::eColorAttachmentOptimal
	};

	vk::AttachmentReference colour_resolve_attachment =
	{
		1,
		vk::ImageLayout::eColorAttachmentOptimal
	};

	std::vector<vk::AttachmentDescription> attachments =
	{
		m_backbuffer.GetAttachmentDesc()
	};

	if (m_multisampling)
	{
		attachments.emplace_back(m_backbuffer.GetResolveAttachmentDesc());
	}

	m_render_pass = VkRes::RenderPass(attachments,
	                                  &colour_attachment, 1,
	                                  nullptr,
	                                  m_multisampling ?
		                                  &colour_resolve_attachment :
		                                  nullptr, 1,
	                                  vk::PipelineBindPoint::eGraphics, g_VkGenerator.Device());
}

void VkTriangleDemo::CreateFrameBuffers()
{
	auto image_views = m_swapchain.ImageViews();
	m_framebuffers.resize(image_views.size());

	for (uint32_t i = 0 ; i < image_views.size() ; ++i)
	{
		const std::vector<vk::ImageView> attachments =
		{
			image_views[i]
		};

		m_framebuffers[i] = VkRes::FrameBuffer(g_VkGenerator.Device(), attachments,
		                                       m_render_pass.Pass(), m_swapchain.Extent(),
		                                       1);
	}
}

void VkTriangleDemo::CreatePipelines()
{}

void VkTriangleDemo::CreateColourResources()
{
	m_backbuffer = VkRes::RenderTarget(g_VkGenerator.PhysicalDevice(), g_VkGenerator.Device(),
	                                   m_swapchain.Extent().width, m_swapchain.Extent().height, m_swapchain.Format(),
	                                   vk::SampleCountFlagBits::e1, vk::ImageTiling::eOptimal,
	                                   vk::ImageUsageFlagBits::eTransientAttachment | vk::ImageUsageFlagBits::eColorAttachment,
	                                   vk::MemoryPropertyFlagBits::eDeviceLocal,
	                                   (m_multisampling) ?
		                                   vk::ImageLayout::eColorAttachmentOptimal :
		                                   vk::ImageLayout::ePresentSrcKHR,
	                                   m_command, g_VkGenerator.GraphicsQueue());
}

void VkTriangleDemo::CreateDepthResources()
{}
