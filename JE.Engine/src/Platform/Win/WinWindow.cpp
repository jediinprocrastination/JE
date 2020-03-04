#include "Jepch.h"

#include "Je/Window.h"
#include "WinWindow.h"

namespace Je
{
	WinWindow::WinWindow(const WindowProperties& properties)
	{
		_hwnd = nullptr;
		_state = new WinState();
		_state->SetCallback([this](const UINT* const umsg)
		{
				return WinWindow::OnWindowCallback(umsg);
		});

		_data.Title = properties.Title;
		_data.Height = properties.Height;
		_data.Width = properties.Width;

		WinWindow::Init();
	}
	
	WinWindow::~WinWindow()
	{
		WinWindow::Shutdown();
	}

	void WinWindow::Init()
	{
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
			/* LPVOID lpParam       */ _state);

		ShowWindow(_hwnd, 1);
		UpdateWindow(_hwnd);
	}

	void WinWindow::OnUpdate()
	{
		MSG msg;

		if (PeekMessage(&msg, _hwnd, 0, 0, PM_REMOVE)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			/* Rendering Staff */
		}

		Sleep(1);
	}

	void WinWindow::Shutdown()
	{
	}

	bool WinWindow::OnWindowCallback(const UINT* const umsg)
	{
		return false;
		/*switch (*umsg)
		{
		case WM_CLOSE: break;
		}*/
	}

	inline WinState* GetAppState(HWND hwnd)
	{
		LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
		WinState* state = reinterpret_cast<WinState*>(ptr);

		return state;
	}

	inline void SetAppState(HWND hwnd, const LPARAM lparam)
	{
		CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lparam);
		WinState* state = reinterpret_cast<WinState*>(pCreate->lpCreateParams);
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)state);
	}

	LRESULT CALLBACK WndProc(
		HWND hwnd, const UINT umsg, const 
		WPARAM wparam, const LPARAM lparam)
	{
		WinState* state;

		if (umsg == WM_CREATE)
		{
			SetAppState(hwnd, lparam);
		}
		else
		{
			state = GetAppState(hwnd);

			if (state != nullptr && 
					state->WndProcCallback((UINT*)&umsg))
				return 0;
		}

		return DefWindowProc(hwnd, umsg, wparam, lparam);
	}
}
