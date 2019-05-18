#include "include/InputManager.h"

eKeyState gAllKeyStates[int(eKeyCodes::NumOfKeyCodes)];

void InitialiseInput()
{
	for (auto i = 0 ; i < int(eKeyCodes::NumOfKeyCodes) ; ++i)
	{
		gAllKeyStates[i] = eKeyState::NotPressed;
	}
}

eKeyState ReportKeyState(eKeyCodes _keyCode)
{
	return gAllKeyStates[static_cast<int>(_keyCode)];
}

void KeyEvent(GLFWwindow* _window, int key, int scancode, int action, int mods)
{
	if (action != 0)
	{
		if (gAllKeyStates[key] == eKeyState::NotPressed)
		{
			gAllKeyStates[key] = eKeyState::Pressed;
		}
		else
		{
			gAllKeyStates[key] = eKeyState::Held;
		}
	}
	else
	{
		gAllKeyStates[key] = eKeyState::NotPressed;
	}
}

bool KeyHit(eKeyCodes _keyCode)
{
	int location = static_cast<int>(_keyCode);
	if (gAllKeyStates[int(location)] == eKeyState::Pressed)
	{
		gAllKeyStates[int(location)] = eKeyState::Held;
		return true;
	}
	return false;
}

bool KeyHeld(eKeyCodes _keyCode)
{
	int location = static_cast<int>(_keyCode);
	if (gAllKeyStates[location] == eKeyState::NotPressed)
	{
		return false;
	}
	gAllKeyStates[location] = eKeyState::Held;
	return true;
}
