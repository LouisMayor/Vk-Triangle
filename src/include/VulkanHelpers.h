#pragma once

#include "Command.h"

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

	static uint32_t FindMemoryType(vk::PhysicalDevice      _physical_device,
	                               uint32_t                _filter_type,
	                               vk::MemoryPropertyFlags _memory_property_flags)
	{
		vk::PhysicalDeviceMemoryProperties mem_properties = _physical_device.getMemoryProperties();

		for (uint32_t i = 0 ; i < mem_properties.memoryTypeCount ; ++i)
		{
			if (_filter_type & (1 << i) &&
				(mem_properties.memoryTypes[i].propertyFlags & _memory_property_flags) == _memory_property_flags)
			{
				return i;
			}
		}

		assert(( "failed to find suitable memory type", true ));

		return -1; // overflow
	}

	static std::tuple<vk::Image, vk::DeviceMemory> CreateImage(vk::Device                 _device,
	                                                           vk::PhysicalDevice         _physical_device,
	                                                           uint32_t                   _width,
	                                                           uint32_t                   _height,
	                                                           vk::Format                 _format,
	                                                           uint32_t                   _mip_levels,
	                                                           vk::SampleCountFlagBits    _sample_flag,
	                                                           vk::ImageTiling            _tiling,
	                                                           vk::ImageUsageFlags        _usage,
	                                                           vk::MemoryPropertyFlagBits _properties)
	{
		vk::ImageCreateInfo create_info =
		{
			{},
			vk::ImageType::e2D,
			_format,
			vk::Extent3D(_width, _height, 1u),
			_mip_levels,
			1,
			_sample_flag,
			_tiling,
			_usage,
			vk::SharingMode::eExclusive,
			0,
			nullptr,
			vk::ImageLayout::eUndefined
		};

		vk::Image image;
		auto      image_result = _device.createImage(&create_info, nullptr, &image);

		assert(("Failed to create image", image_result == vk::Result::eSuccess));

		vk::MemoryRequirements mem_requirements = _device.getImageMemoryRequirements(image);

		vk::MemoryAllocateInfo allocate_info =
		{
			mem_requirements.size,
			FindMemoryType(_physical_device, mem_requirements.memoryTypeBits, _properties)
		};

		vk::DeviceMemory image_memory;
		auto             mem_result = _device.allocateMemory(&allocate_info, nullptr, &image_memory);

		_device.bindImageMemory(image, image_memory, 0);

		return std::make_tuple(image, image_memory);
	}

	static void TransitionImageLayout(vk::Device      _device,
	                                  VkRes::Command  _cmd,
	                                  vk::Queue       _queue,
	                                  vk::Image       _image,
	                                  vk::Format      _format,
	                                  vk::ImageLayout old_layout,
	                                  vk::ImageLayout new_layout,
	                                  uint32_t        _mip_levels)
	{ }
}
