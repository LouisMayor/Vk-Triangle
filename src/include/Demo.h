#pragma once

#include "App.h"
#include "vulkan_resources.h"

class VkDemo
{
public:

	VkDemo() = default;

	explicit VkDemo(const VkApp& _app_instance) : m_app_instance(_app_instance)
	{}

	VkDemo(const VkDemo& _other) = delete;

	VkDemo(VkDemo&& _other) noexcept = delete;

	VkDemo& operator=(const VkDemo& _other) = delete;

	VkDemo& operator=(VkDemo&& _other) noexcept = delete;

	virtual ~VkDemo()
	{}

	void virtual Setup() = 0;

	void virtual Run() = 0;

	void virtual Shutdown() = 0;

private:
	void virtual SubmitQueue() = 0;

	void virtual RecordCmdBuffer() = 0;

	void virtual CreateSwapchain() = 0;

	void virtual CreateImageViews() = 0;

	void virtual CreateCmdPool() = 0;

	void virtual CreateRenderPasses() = 0;

	void virtual CreateFrameBuffers() = 0;

	void virtual CreatePipelines() = 0;

	void virtual CreateColourResources() = 0;

	void virtual CreateDepthResources() = 0;

protected:
	VkApp m_app_instance;
};
