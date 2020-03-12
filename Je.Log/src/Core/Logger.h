#pragma once

#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

#include "ConsoleColors.h"

namespace Je
{
	class __declspec(dllexport) Logger
	{
	public:
		void Info(std::string* message);
		template<typename... T>
		void Info(std::string* message, const T&... args);
		void Warn(std::string* message);
		template<typename... T>
		void Warn(std::string* message, const T&... args);
		void Error(std::string* message);
		template<typename... T>
		void Error(std::string* message, const T&... args);

	private:
		void SetForegroundColor(const ConsoleColors color);
		std::string Logger::GetMessageLine(const std::string* message);
	};

	#define PRINT_MESSAGE_LINE(msg) { std::string line = GetMessageLine(msg); printf(line.c_str()); }
	#define PRINT_USING_COLOR(msg, color) { SetForegroundColor(color); PRINT_MESSAGE_LINE(msg); SetForegroundColor(color); }

	template<typename... T>
	void Logger::Info(std::string* message, const T&... args)
	{
		SetForegroundColor(ConsoleColors::Cyan);
		std::string line = GetMessageLine(message);
		printf(line.c_str(), args...);
		SetForegroundColor(ConsoleColors::White);
	}

	template<typename... T>
	void Logger::Warn(std::string* message, const T&... args)
	{
		SetForegroundColor(ConsoleColors::Yellow);
		std::string line = GetMessageLine(message);
		printf(line.c_str(), args...);
		SetForegroundColor(ConsoleColors::White);
	}

	template<typename... T>
	void Logger::Error(std::string* message, const T&... args)
	{
		SetForegroundColor(ConsoleColors::Red);
		std::string line = GetMessageLine(message);
		printf(line.c_str(), args...);
		SetForegroundColor(ConsoleColors::White);
	}
}
