#include "Jepch.h"
#include "Application.h"
#include "Window.h"

namespace Je
{
	Application::Application() = default;
	Application::~Application() = default;

	void Application::Run()
	{
		Log::Init();
		JE_INFO("This is the info!");
		/*Log::Info("This is the {0}!", "info");
		Log::Warn("This is the warning!");
		Log::Warn("This is the {0}!", "warning");
		Log::Error("This is the error!");
		Log::Error("This is the {0}!", "error");*/
		
		auto win = std::unique_ptr<Window>(Window::Create());

		while (true)
		{
			win->OnUpdate();
		}
	}
}
