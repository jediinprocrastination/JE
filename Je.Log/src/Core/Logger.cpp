
#include "Logger.h"

#ifdef JE_PLATFORM_WIN
#include <Windows.h>
#endif

namespace Je
{
	void Logger::Info(std::string* message)
	{
		PRINT_USING_COLOR(message, ConsoleColors::Cyan);
	}

	void Logger::Warn(std::string* message)
	{
		SetForegroundColor(ConsoleColors::Yellow);
		PRINT_MESSAGE_LINE(message);
		SetForegroundColor(ConsoleColors::White);
	}

	void Logger::Error(std::string* message)
	{
		SetForegroundColor(ConsoleColors::Red);
		PRINT_MESSAGE_LINE(message);
		SetForegroundColor(ConsoleColors::White);
	}
	
	void Logger::SetForegroundColor(const ConsoleColors color)
	{
		#ifdef JE_PLATFORM_WIN
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (int)color);
		#endif
	}

	std::string Logger::GetMessageLine(const std::string* message)
	{
		auto nowTimePoint = std::chrono::system_clock::now();
		auto nowTime = std::chrono::system_clock::to_time_t(nowTimePoint);
		
		std::stringstream buffer;
		buffer << std::put_time(std::localtime(&nowTime), "%H:%M:%S");

		auto now = buffer.str();
		auto line = "[" + now + "] " + (*message) + "\n";

		return line;
	}
}
