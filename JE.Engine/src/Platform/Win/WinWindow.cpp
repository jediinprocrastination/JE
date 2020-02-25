#include "Jepch.h"
#include "Je/Window.h"
#include "WinWindow.h"

namespace Je
{
	WinWindow::WinWindow(const WindowProperties& properties)
	{
		WinWindow::Init(properties);
	}
	
	WinWindow::~WinWindow()
	{
		WinWindow::Shutdown();
	}

	void WinWindow::OnUpdate() 
	{
	}

	void WinWindow::Init(const WindowProperties& properties)
	{
		_data.Title = properties.Title;
		_data.Height = properties.Height;
		_data.Width = properties.Width;
	}

	void WinWindow::Shutdown()
	{
	}
}
