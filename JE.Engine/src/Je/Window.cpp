#include "Jepch.h"
#include "Window.h"

#ifdef JE_PLATFORM_WIN
#include "Platform/Win/WinWindow.h"
#else
#error Windows only!
#endif

namespace Je
{
#ifdef JE_PLATFORM_WIN
	Window* Window::Create(const WindowProperties& properties)
	{
		return new Je::WinWindow(properties);
	}
#else
#error Windows only!
#endif
}
