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

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	void WinWindow::Init(const WindowProperties& properties)
	{
		_data.Title = properties.Title;
		_data.Height = properties.Height;
		_data.Width = properties.Width;

		auto title = std::wstring(_data.Title.begin(), _data.Title.end());
		wchar_t CLASS_NAME[] = L"The win window class";

		WNDCLASS wc = {};
		HINSTANCE hInstance = GetModuleHandle(NULL);
		
		wc.lpszClassName = CLASS_NAME;
		wc.lpfnWndProc = WndProc;
		wc.hInstance = hInstance;

		RegisterClass(&wc);

		_hwnd = CreateWindowEx(
			/* DWORD dwExStyle      */ 0,
			/* LPCWSTR lpClassName  */ CLASS_NAME,
			/* LPCWSTR lpWindowName */ title.c_str(),
			/* DWORD dwStyle        */ WS_OVERLAPPEDWINDOW,
			/* int X                */ CW_USEDEFAULT, 
			/* int Y                */ CW_USEDEFAULT, 
			/* int nWidth           */ _data.Width, 
			/* int nHeight          */ _data.Height,
			/* HWND hWndParent      */ NULL,
			/* HMENU hMenu          */ NULL,
			/* HINSTANCE hInstance  */ hInstance,
			/* LPVOID lpParam       */ NULL);

		if (_hwnd != NULL)
		{
			ShowWindow(_hwnd, 1);
			UpdateWindow(_hwnd);
		}
	}

	void WinWindow::OnUpdate()
	{
		MSG msg;

		if (PeekMessage(&msg, _hwnd, 0, 0, PM_REMOVE)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT) 
			{
				//bDone = TRUE;
			}
		}
		else
		{
			/* do rendering here */
		}
	}

	void WinWindow::Shutdown()
	{
	}

	LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_QUIT:
		case WM_DESTROY:
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
		return 0;
	}
}
