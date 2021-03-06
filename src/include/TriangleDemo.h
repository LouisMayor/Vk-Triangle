#pragma once

#include "Demo.h"

class VkTriangleDemo : public VkDemo
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

	static VKAPI_ATTR VkBool32 VKAPI_CALL TriangleDemoDebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT      _message_severity,
	                                                                VkDebugUtilsMessageTypeFlagsEXT             _message_type,
	                                                                const VkDebugUtilsMessengerCallbackDataEXT* _p_callback_data,
	                                                                void*                                       _p_user_data);

private:

	void SubmitQueue() override;

	void CreateSyncObjects() override;

	void RecordCmdBuffer() override;

	void CreateSwapchain() override;

	void CreateShaders() override;

	void CreateCmdPool() override;

	void CreateRenderPasses() override;

	void CreateFrameBuffers() override;

	void CreatePipelines() override;

	void CreateColourResources() override;

	void CreateDepthResources() override;

	void CleanSwapchain() override;

	void RecreateSwapchain() override;

	void CreateCmdBuffers( ) override;

	VkRes::Swapchain                m_swapchain;
	VkRes::Command                  m_command;
	VkRes::RenderTarget             m_backbuffer;
	VkRes::RenderPass               m_render_pass;
	std::vector<VkRes::FrameBuffer> m_framebuffers;
	VkRes::GraphicsPipeline         m_graphics_pipeline;
	VkRes::Shader                   m_vert;
	VkRes::Shader                   m_frag;
	std::vector<VkRes::Fence>       m_inflight_fences;
	std::vector<VkRes::Semaphore>   m_image_available_semaphores;
	std::vector<VkRes::Semaphore>   m_render_finished_semaphores;

	bool m_multisampling = false;
};
