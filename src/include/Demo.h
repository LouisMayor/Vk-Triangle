#pragma once

#include "App.h"

class VkDemo
{
public:
	void virtual Setup() = 0;

protected:
	VkApp m_app_instance;
};
