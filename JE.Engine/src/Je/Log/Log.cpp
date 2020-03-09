#include "Jepch.h"
#include "Log.h"

namespace Je
{
	//std::shared_ptr<spdlog::logger> Log::_coreLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		//_coreLogger = spdlog::stdout_color_mt("Je");
	}
}
