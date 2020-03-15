#pragma once

#include "Je/Events/Event.h"
#include "Core.h"

namespace Je
{
	class JE_API Application
	{
	public:
		Application();
		virtual ~Application();

		static void Run();

	private:
		static void OnEventCallback(const Event& event);
	};

	Application* CreateApplication();
}
