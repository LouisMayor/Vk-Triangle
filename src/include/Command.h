#pragma once

class Command
{
public:
	Command() = default;

	Command(vk::Device _device, VkGen::QueueFamilyIndices _queue_family_indices)
	{
		vk::CommandPoolCreateInfo create_info =
		{
			vk::CommandPoolCreateFlagBits::eResetCommandBuffer,
			static_cast<uint32_t>(_queue_family_indices.graphics_family)
		};

		auto result = _device.createCommandPool(&create_info, nullptr, &m_command_pool);

		assert(("Failed to create command pool", result == vk::Result::eSuccess));
	}

	void FreeCommandBuffers(vk::Device _device)
	{
		_device.freeCommandBuffers(m_command_pool, static_cast<uint32_t>(m_command_buffers.size()), m_command_buffers.data());
	}

	void Destroy(vk::Device _device)
	{
		FreeCommandBuffers(_device);
		_device.destroyCommandPool(m_command_pool);
	}

	vk::CommandPool& CommandPool()
	{
		return m_command_pool;
	}

	std::vector<vk::CommandBuffer>& CommandBuffers()
	{
		return m_command_buffers;
	}

	int CommandBufferCount()
	{
		return m_command_buffers.size();
	}

private:
	vk::CommandPool                m_command_pool;
	std::vector<vk::CommandBuffer> m_command_buffers;
};
