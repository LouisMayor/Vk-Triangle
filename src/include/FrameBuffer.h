#pragma once

namespace VkRes
{
	class FrameBuffer
	{
	public:
	private:
		vk::FramebufferCreateInfo m_framebuffer_info;
		vk::Framebuffer           m_framebuffer;
	};
}
