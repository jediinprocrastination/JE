#include "Jepch.h"
#include "Application.h"
#include "Window.h"

#include "Je/Events/Event.h"
#include "Je/Events/MouseEvent.h"
#include "Je/Log.h"

namespace Je
{
	Application::Application() = default;
	Application::~Application() = default;

	void Application::Run()
	{
		INFO("Application started.");

		auto win = std::unique_ptr<Window>(Window::Create());
		win->SetCallback([](Event& e) { Application::OnEventCallback(e); });

		while (true)
		{
			win->OnUpdate();
		}
	}

	void Application::OnEventCallback(const Event& event)
	{
		auto move = (MouseMoveEvent&)event;

		WARN("Position: %f : %f", move.GetX(), move.GetY())
	}
}
