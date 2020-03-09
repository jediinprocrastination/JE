#pragma once

#include "Jepch.h"
#include "Je/Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Je
{
	class JE_API Log
	{
	public:
		static void Init();
		static void Info(std::string& message);
		template<typename T>
		static void Warn(const T& msg);
		static void Error(std::string& message);

	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
	};
}
