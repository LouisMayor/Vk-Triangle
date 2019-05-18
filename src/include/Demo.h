#pragma once

#include "App.h"

class VkDemo
{
public:
	void virtual Setup() = 0;

	void virtual Run() = 0;

	void virtual Shutdown() = 0;

protected:
	VkApp m_app_instance;
};
