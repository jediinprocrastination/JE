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
	
	private:
		inline static Logger* GetLogger()
		{
			static Logger s_logger;
			return &s_logger;
		}
	};
}
