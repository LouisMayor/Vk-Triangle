#pragma once

#include "Demo.h"

class VkTriangleDemo : VkDemo
{
public:

	VkTriangleDemo() = default;

	explicit VkTriangleDemo(const VkApp& _app_instance) : VkDemo(_app_instance)
	{}

	VkTriangleDemo(const VkTriangleDemo& _other) = delete;

	VkTriangleDemo(VkTriangleDemo&& _other) noexcept = delete;

	VkTriangleDemo& operator=(const VkTriangleDemo& _other) = delete;

	VkTriangleDemo& operator=(VkTriangleDemo&& _other) noexcept = delete;

	~VkTriangleDemo() override
	{ }

	void Setup() override;

	void Run() override;

	void Shutdown() override;

	static VKAPI_ATTR VkBool32 VKAPI_CALL TriangleDemoDebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT      _messageSeverity,
	                                                                VkDebugUtilsMessageTypeFlagsEXT             _messageType,
	                                                                const VkDebugUtilsMessengerCallbackDataEXT* _pCallbackData,
	                                                                void*                                       _pUserData);

private:

	void SubmitQueue() override;

	void RecordCmdBuffer() override;

	void CreateSwapchain() override;

	void CreateCmdPool() override;

	void CreateRenderPasses() override;

	void CreateFrameBuffers() override;

	void CreatePipelines() override;

	void CreateColourResources() override;

	void CreateDepthResources() override;

	VkRes::Swapchain    m_swapchain;
	VkRes::Command      m_command;
	VkRes::RenderTarget m_backbuffer;
	VkRes::RenderPass   m_render_pass;

	bool m_multisampling = false;
};
