#pragma once

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

	InputManager m_input_manger;
};
