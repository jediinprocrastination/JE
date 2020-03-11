#pragma once

#include <string>

namespace Je
{
	class __declspec(dllexport) Logger
	{
	public:
		void Info(std::string* message);
		template<typename... T>
		void Info(std::string* message, const T&... args);
		// void Warn(std::string& message);
		// void Error(std::string& message);
	};

	template<typename... T>
	void Logger::Info(std::string* message, const T&... args)
	{
		const char* cstr = (*message).c_str();
		printf(cstr, args...);
	}
}
