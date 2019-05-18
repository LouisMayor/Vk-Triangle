#pragma once

#include "Logger.h"
#include "Vk-Generator/VkGenerator.hpp"
#include "InputManager.h"

class VkApp
{
public:
	void Start();

	void Update();

	void Close();

	bool ShouldStop();

private:

	bool Input();

	InputManager m_input_manager;
};
