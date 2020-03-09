#include "Jepch.h"
#include "Log.h"

namespace Je
{
	std::shared_ptr<spdlog::logger> Log::_coreLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		_coreLogger = spdlog::stdout_color_mt("Je");
	}

	void Log::Info(std::string& message)
	{
		_coreLogger->info(message);
	}

	template<typename T>
	void Log::Warn(const T& msg)
	{
		_coreLogger->warn(msg);
	}

	void Log::Error(std::string& message)
	{
		_coreLogger->error(message);
	}
}
