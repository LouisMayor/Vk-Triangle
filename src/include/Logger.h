#pragma once

#include <Windows.h>
#include <string>

#undef CreateWindow // Conflict with Window's function and VkGenerator

// removing template argument deduction (https://stackoverflow.com/questions/41634538/prevent-implicit-template-instantiation)
template <typename T> struct disable_arg_deduction
{
	using type = T;
};

class Logger
{
public:
	Logger() = default;

	~Logger()
	{ }

	Logger(HANDLE _consoleHandle)
	{
		if (_consoleHandle == nullptr)
		{
			return;
		}

		hConsole = _consoleHandle;
		mEnabled = true;
	}

	void Create(HANDLE _consoleHandle)
	{
		if (_consoleHandle == nullptr)
		{
			return;
		}

		hConsole = _consoleHandle;
		mEnabled = true;
	}

	template <typename T> void Log(const typename disable_arg_deduction<T>::type& _object,
	                               const std::string                              _message,
	                               const std::string                              _functionReporting = "",
	                               const std::string                              _file              = "")
	{
		if (!IsEnabled())
		{
			return;
		}

		SetLogColour();

		std::printf("Log: ");
		_file != "" ?
			std::printf("%s: ", _file.c_str()) :
			0;
		_functionReporting != "" ?
			std::printf("%s: ", _functionReporting.c_str()) :
			0;
		std::printf("%s", _message.c_str());
		std::cout << _object;

		ResetColour();
	}

	void Log(const std::string _message, const std::string _functionReporting = "", const std::string _file = "")
	{
		if (!IsEnabled())
		{
			return;
		}

		SetLogColour();

		std::printf("Log: ");
		_file != "" ?
			std::printf("%s: ", _file.c_str()) :
			0;
		_functionReporting != "" ?
			std::printf("%s: ", _functionReporting.c_str()) :
			0;
		std::printf("%s\n", _message.c_str());

		ResetColour();
	}

	template <typename T> void Info(const typename disable_arg_deduction<T>::type& _object,
	                                const std::string                              _message,
	                                const std::string                              _functionReporting = "",
	                                const std::string                              _file              = "")
	{
		if (!IsEnabled())
		{
			return;
		}

		SetLogColour();

		std::printf("Info: ");
		_file != "" ?
			std::printf("%s: ", _file.c_str()) :
			0;
		_functionReporting != "" ?
			std::printf("%s: ", _functionReporting.c_str()) :
			0;
		std::printf("%s", _message.c_str());
		std::cout << _object;

		ResetColour();
	}

	void Info(const std::string _message, const std::string _functionReporting = "", const std::string _file = "")
	{
		if (!IsEnabled())
		{
			return;
		}

		SetLogColour();

		std::printf("Info: ");
		_file != "" ?
			std::printf("%s: ", _file.c_str()) :
			0;
		_functionReporting != "" ?
			std::printf("%s: ", _functionReporting.c_str()) :
			0;
		std::printf("%s\n", _message.c_str());

		ResetColour();
	}

	template <typename T> void Warning(const typename disable_arg_deduction<T>::type& _object,
	                                   const std::string                              _message,
	                                   const std::string                              _functionReporting = "",
	                                   const std::string                              _file              = "")
	{
		if (!IsEnabled())
		{
			return;
		}

		SetWarningColour();

		std::printf("Warning: ");
		_file != "" ?
			std::printf("%s: ", _file.c_str()) :
			0;
		_functionReporting != "" ?
			std::printf("%s: ", _functionReporting.c_str()) :
			0;
		std::printf("%s", _message.c_str());
		std::cout << _object;

		ResetColour();
	}

	void Warning(const std::string _message, const std::string _functionReporting = "", const std::string _file = "")
	{
		if (!IsEnabled())
		{
			return;
		}

		SetWarningColour();

		std::printf("Warning: ");
		_file != "" ?
			std::printf("%s: ", _file.c_str()) :
			0;
		_functionReporting != "" ?
			std::printf("%s: ", _functionReporting.c_str()) :
			0;
		std::printf("%s\n", _message.c_str());

		ResetColour();
	}

	template <typename T> void Error(const typename disable_arg_deduction<T>::type& _object,
	                                 const std::string                              _message,
	                                 const std::string                              _functionReporting = "",
	                                 const std::string                              _file              = "")
	{
		if (!IsEnabled())
		{
			return;
		}

		SetErrorColour();

		std::printf("Error: ");
		_file != "" ?
			std::printf("%s: ", _file.c_str()) :
			0;
		_functionReporting != "" ?
			std::printf("%s: ", _functionReporting.c_str()) :
			0;
		std::printf("%s", _message.c_str());
		std::cout << _object;

		ResetColour();
	}

	void Error(const std::string _message, const std::string _functionReporting = "", const std::string _file = "")
	{
		if (!IsEnabled())
		{
			return;
		}

		SetErrorColour();

		std::printf("Error: ");
		_file != "" ?
			std::printf("%s: ", _file.c_str()) :
			0;
		_functionReporting != "" ?
			std::printf("%s: ", _functionReporting.c_str()) :
			0;
		std::printf("%s\n", _message.c_str());

		ResetColour();
	}

	inline bool IsEnabled() const
	{
		return mEnabled;
	}

private:
	void SetLogColour()
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}

	void SetWarningColour()
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}

	void SetErrorColour()
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	}

	void ResetColour()
	{
		SetConsoleTextAttribute(hConsole, 15);
	}

private:
	bool   mEnabled = false;
	HANDLE hConsole = nullptr;
};
