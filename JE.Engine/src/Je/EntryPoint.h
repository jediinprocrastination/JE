#pragma once

#ifdef JE_PLATFORM_WIN

#if JE_BUILD
#include "Log/Log.h"
#endif

extern Je::Application* Je::CreateApplication();

int main(int argc, char** argv)
{
	Je::Log::Init();

	auto app = Je::CreateApplication();
	app->Run();
	delete app;
}

#endif
