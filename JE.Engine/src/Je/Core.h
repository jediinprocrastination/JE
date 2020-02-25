#pragma once

#ifdef JE_PLATFORM_WIN
	#ifdef JE_BUILD
		#define JE_API __declspec(dllexport)
	#else
		#define JE_API __declspec(dllimport)
	#endif
#else
	#error Windows only!
#endif
