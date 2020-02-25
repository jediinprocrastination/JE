#include "Jepch.h"
#include "Application.h"

namespace Je
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Application is running!" << std::endl;
		while (true);
	}
}
