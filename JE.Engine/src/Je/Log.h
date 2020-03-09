#pragma once

#include "Jepch.h"
#include <spdlog\spdlog.h>

namespace Je
{
	class Log
	{
	public:
		template<typename T>
		inline static void Info(const T& message)
		{
			spdlog::set_pattern(PATTERN);
			spdlog::info(message);
		}

		template<typename... Args>
		inline static void Info(std::string message, const Args&... args)
		{
			spdlog::set_pattern(PATTERN);
			spdlog::info(message, args...);
		}

		template<typename... Args>
		inline static void Error(std::string message, const Args&... args)
		{
			spdlog::set_pattern(PATTERN);
			spdlog::error(message, args...);
		}

	private:
		static const std::string PATTERN;
	};

	const std::string Log::PATTERN = "%^[%T] %v%$";
}
