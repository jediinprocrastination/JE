#pragma once

#include "Jepch.h"
#include <Je.Log.h>

namespace Je
{
	class Log
	{
	public:
		inline static void Info(const std::string message)
		{
			GetLogger()->Info((std::string*)&message);
		}

		template<typename... T>
		inline static void Info(std::string message, const T&... args)
		{
			GetLogger()->Info(&message, (args)...);
		}

		inline static void Warn(const std::string message)
		{
			GetLogger()->Warn((std::string*) & message);
		}

		template<typename... T>
		inline static void Warn(std::string message, const T&... args)
		{
			GetLogger()->Warn(&message, (args)...);
		}

		inline static void Error(const std::string message)
		{
			GetLogger()->Error((std::string*) & message);
		}

		template<typename... T>
		inline static void Error(std::string message, const T&... args)
		{
			GetLogger()->Error(&message, (args)...);
		}
	
	private:
		inline static Logger* GetLogger()
		{
			static Logger s_logger;
			return &s_logger;
		}
	};
}

#ifndef _INFO
#define INFO(...) { Je::Log::Info(__VA_ARGS__); }
#endif // !_INFO

#ifndef _WARN
#define WARN(...) { Je::Log::Warn(__VA_ARGS__); }
#endif // !_WARN

#ifndef _ERROR
#define ERROR(...) { Je::Log::Error(__VA_ARGS__); }
#endif // !_ERROR
