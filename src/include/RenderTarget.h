#pragma once

class RenderTarget
{
public:

	RenderTarget() = default;

	RenderTarget(vk::PhysicalDevice         _physical_device,
	             vk::Device                 _device,
	             uint32_t                   _width,
	             uint32_t                   _height,
	             vk::Format                 _format,
	             vk::SampleCountFlagBits    _sample_count,
	             vk::ImageTiling            _image_tiling,
	             vk::ImageUsageFlags        _usage,
	             vk::MemoryPropertyFlagBits _properties,
	             vk::ImageLayout            _finalLayout,
	             vk::CommandPool            _cmd_pool,
	             vk::Queue                  _queue)
	{
		auto image_data = VkRes::CreateImage(_device, _physical_device, _width, _height,
		                                     _format, 1, _sample_count, _image_tiling,
		                                     _usage, _properties);

		m_image        = std::get<0>(image_data);
		m_image_memory = std::get<1>(image_data);
		m_image_view   = VkRes::CreateImageView(_device, m_image, _format, vk::ImageAspectFlagBits::eColor, 1);

		VkRes::TransitionImageLayout(_device, _cmd_pool, _queue,
		                             m_image, _format, vk::ImageLayout::eUndefined,
		                             vk::ImageLayout::eColorAttachmentOptimal, 1u);

		CreateAttachmentDesc(_format, _sample_count, _finalLayout);

		CreateResolveAttachmentDesc(_format, _sample_count);
	}

	void Destroy(vk::Device _device)
	{
		if (m_image_view != nullptr)
		{
			_device.destroyImageView(m_image_view);
			m_image_view = nullptr;
		}

		if (m_image != nullptr)
		{
			_device.destroyImage(m_image);
			m_image = nullptr;
		}

		if (m_image_memory != nullptr)
		{
			_device.freeMemory(m_image_memory);
			m_image_memory = nullptr;
		}
	}

private:

	void CreateAttachmentDesc(vk::Format _format, vk::SampleCountFlagBits _num_samples, vk::ImageLayout _final_layout)
	{
		m_attachment_desc =
		{
			{},
			_format,
			_num_samples,
			vk::AttachmentLoadOp::eLoad,
			vk::AttachmentStoreOp::eStore,
			vk::AttachmentLoadOp::eLoad,
			vk::AttachmentStoreOp::eStore,
			vk::ImageLayout::eUndefined,
			_final_layout
		};
	}

	void CreateResolveAttachmentDesc(vk::Format _format, vk::SampleCountFlagBits _num_samples)
	{
		m_resolve_attachment_desc =
		{
			{},
			_format,
			_num_samples,
			vk::AttachmentLoadOp::eLoad,
			vk::AttachmentStoreOp::eStore,
			vk::AttachmentLoadOp::eLoad,
			vk::AttachmentStoreOp::eStore,
			vk::ImageLayout::eUndefined,
			vk::ImageLayout::ePresentSrcKHR
		};
	}

	vk::Image        m_image        = nullptr;
	vk::ImageView    m_image_view   = nullptr;
	vk::DeviceMemory m_image_memory = nullptr;

	vk::AttachmentDescription m_attachment_desc;
	vk::AttachmentDescription m_resolve_attachment_desc;
};
