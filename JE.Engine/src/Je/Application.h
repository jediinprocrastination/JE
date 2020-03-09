#pragma once

#include "Core.h"

namespace Je
{
	class JE_API Application
	{
	public:
		Application();
		virtual ~Application();

		static void Run();
	};

	Application* CreateApplication();
}
