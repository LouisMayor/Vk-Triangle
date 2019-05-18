#pragma once

#include "Vk-Generator/VkGenerator.hpp"

enum class eKeyState : int;

enum class eKeyCodes : int;

class InputManager
{
public:
	void InitialiseInput();

	void KeyEvent(GLFWwindow* _window, int key, int scancode, int action, int mods);

	eKeyState ReportKeyState(eKeyCodes _keyCode);

	bool KeyHit(eKeyCodes _keyCode);

	bool KeyHeld(eKeyCodes _keyCode);
};
