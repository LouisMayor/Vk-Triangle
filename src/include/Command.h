#pragma once

namespace VkRes
{
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

			const auto result = _device.createCommandPool(&create_info, nullptr, &m_command_pool);

			assert(("Failed to create command pool", result == vk::Result::eSuccess));
		}

		vk::CommandBuffer BeginSingleTimeCmds(vk::Device _device)
		{
			const vk::CommandBufferAllocateInfo alloc_info =
			{
				CommandPool(),
				vk::CommandBufferLevel::ePrimary,
				1
			};

			auto cmd_buffer = _device.allocateCommandBuffers(alloc_info);

			assert(("Failed to allocate command buffer", cmd_buffer.size() > 0));

			vk::CommandBufferBeginInfo begin_info =
			{
				vk::CommandBufferUsageFlagBits::eOneTimeSubmit,
				nullptr
			};

			const auto result = cmd_buffer[0].begin(&begin_info);

			assert(("Failed to begin command buffer", result == vk::Result::eSuccess));

			return cmd_buffer[0];
		}

		void EndSingleTimeCmds(vk::Device _device, vk::CommandBuffer _cmd_buffer, vk::Queue _queue)
		{
			_cmd_buffer.end();

			vk::SubmitInfo submit_info =
			{
				0,
				nullptr,
				nullptr,
				1,
				&_cmd_buffer,
				0,
				nullptr
			};

			const auto result = _queue.submit(1, &submit_info, nullptr);

			assert(("Failed to submit single time command queue", result == vk::Result::eSuccess));

			_queue.waitIdle();

			_device.freeCommandBuffers(CommandPool(), 1, &_cmd_buffer);
		}

		vk::CommandBuffer EndSingleTimeCmds(vk::Device _device)
		{ }

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
}
