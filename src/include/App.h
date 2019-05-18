#pragma once

#define GLFW_INCLUDE_VULKAN
#include "glfw3.h"

#include "Vk-Generator/VkGenerator.hpp"
#include "InputManager.h"

extern VkGen::VkGenerator g_VkGenerator;

class VkApp
{
public:
	void Start();

	void Update();

	void Close();

	bool ShouldStop();

private:

	bool Input();
};
