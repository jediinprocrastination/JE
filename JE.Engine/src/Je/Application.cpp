#include "Jepch.h"
#include "Application.h"
#include "Window.h"
#include "Je/Log.h"

namespace Je
{
	Application::Application() = default;
	Application::~Application() = default;

	void Application::Run()
	{
		INFO("Application started.");

		auto win = std::unique_ptr<Window>(Window::Create());

		while (true)
		{
			win->OnUpdate();
		}
	}
}
