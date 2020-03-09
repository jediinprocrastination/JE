#pragma once

#include "Jepch.h"
#include "Je/Core.h"

#include "spdlog/spdlog.h"
//#include "spdlog/sinks/stdout_color_sinks.h"

namespace Je
{
	class JE_API Log
	{
	public:
		static void Init();

	private:
		//static std::shared_ptr<spdlog::logger> _coreLogger;
	};
}
