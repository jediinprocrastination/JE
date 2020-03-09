#pragma once

#include "Jepch.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Je
{
	class Log
	{
	public:
		static void Init()
		{
			spdlog::set_pattern("%^[%T] %n: %v%$");
			_coreLogger = spdlog::stdout_color_mt("Je");
		}

		static std::shared_ptr<spdlog::logger>& GetLogger()
		{
			return _coreLogger;
		}
		
	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
	};
}

#define JE_INFO(...) ::Je::Log::GetLogger()->info(__VA_ARGS__);
