
#include "Logger.h"

namespace Je
{
	void Logger::Info(std::string* message)
	{
		const char* cstr = (*message).c_str();
		printf(cstr);
	}
}
