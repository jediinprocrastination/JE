#include "Jepch.h"

#include "GL/glew.h"
#include "GL/gl.h"

#include "Je/Window.h"
#include "WinWindow.h"

namespace Je
{
	WinWindow::WinWindow(const WindowProperties& properties)
	{
		_hwnd = nullptr;
		_state = new WinState();
		
		_state->SetCallback([this](const HWND* hwnd, const UINT* umsg)
		{
			return WinWindow::OnWindowCallback(hwnd, umsg);
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
			/* Just simple example */
			glClearColor(0.129f, 0.586f, 0.949f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			
			SwapBuffers(_dc);
		}

		/* FPS control */
		/* Will be replaced with something meaningful */
		Sleep(1);
	}

	void WinWindow::Shutdown()
	{
	}

	bool WinWindow::OnWindowCallback(const HWND* hwnd, const UINT* umsg)
	{
		if (*umsg == WM_CREATE)			return WinWindow::InitializeGraphicContext(hwnd);
		if (*umsg == WM_SHOWWINDOW)	return false;
		if (*umsg == WM_CLOSE)			return false;
		
		return false;
	}

	bool WinWindow::InitializeGraphicContext(const HWND* hwnd)
	{
		PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | 
			PFD_SUPPORT_OPENGL | 
			PFD_DOUBLEBUFFER,     // Flags
			PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
			32,                   // Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,                   // Number of bits for the depthbuffer
			8,                    // Number of bits for the stencilbuffer
			0,                    // Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		_dc = GetDC(*hwnd);
		int pfdID = ChoosePixelFormat(_dc, &pfd);
		
		if (pfdID == 0) return false;
		if (SetPixelFormat(_dc, pfdID, &pfd) == false) return false;

		_context = wglCreateContext(_dc);
		wglMakeCurrent(_dc, _context);

		auto result = glewInit();
		
		if (result != GLEW_OK)
		{
			auto message = glewGetErrorString(result);
			//Log::Warn(message);
			fprintf(stderr, "Error: %s\n", message);
			return false;
		}
		else
		{
			auto version = glGetString(GL_VERSION);
			//Log::Warn(version);
			fprintf(stdout, "OpenGL version: %s\n", version);
			return true;
		}
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
		
		state = GetAppState(hwnd);

		return 
			(state != nullptr && 
			 state->WndProcCallback((HWND*)&hwnd, (UINT*)&umsg))
				? 0 
				: DefWindowProc(hwnd, umsg, wparam, lparam);
	}
}
