#pragma once

#include "Application.h"

#ifdef JE_PLATFORM_WIN

//extern Je::Application* Je::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Je::CreateApplication();
	app->Run();
	delete app;
}

#endif
