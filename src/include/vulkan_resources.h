#pragma once

namespace VkRes
{
	static vk::ImageView CreateImageView(vk::Device _device, vk::Image            _image,
	                                     vk::Format _format, vk::ImageAspectFlags _aspect_flags,
	                                     uint32_t   _mips_level)
	{
		vk::ImageViewCreateInfo create_info =
		{
			{},
			_image,
			vk::ImageViewType::e2D,
			_format,
			vk::ComponentMapping(vk::ComponentSwizzle::eR, vk::ComponentSwizzle::eG,
			                     vk::ComponentSwizzle::eB, vk::ComponentSwizzle::eA),
			vk::ImageSubresourceRange(_aspect_flags, 0, _mips_level, 0, 1)
		};

		vk::ImageView image_view;
		auto          result = _device.createImageView(&create_info, nullptr, &image_view);

		assert(( "failed to create image view", result == vk::Result::eSuccess ));

		return image_view;
	}

#include "Swapchain.h"

}
