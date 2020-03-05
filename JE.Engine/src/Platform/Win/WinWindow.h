#pragma once

#include "Jepch.h"
#include "Je/Window.h"

namespace Je
{
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	struct WinState 
	{
		using WindowCallback = std::function<bool(const HWND* hwnd, const UINT* const umsg)>;

		WindowCallback WndProcCallback;
		void SetCallback(const WindowCallback callback) { WndProcCallback = callback; }
	};

	class WinWindow : public Window
	{
	public:
		explicit WinWindow(const WindowProperties& properties);
		virtual ~WinWindow();
		void OnUpdate() override;
		unsigned int GetHeight() override { return _data.Height; }
		unsigned int GetWidth() override { return _data.Width; }
		void SetVSync(const bool enabled) override { _data.VSync = enabled; }
		bool IsVSync() const override { return _data.VSync; }
		void SetCallback(const EventCallbackFn& callback) override { _data.EventCallback = callback; }
	
	protected:
		virtual void Init();
		virtual void Shutdown();
		virtual bool OnWindowCallback(const HWND* hwnd, const UINT* umsg);
	
	private:
		bool InitializeGraphicContext(const HWND* hwnd);

		struct WinData
		{
			std::string Title;
			unsigned int Height, Width;
			bool VSync;
			EventCallbackFn EventCallback;
		};

		WinData _data;
		WinState* _state;
		HWND _hwnd;
		HDC _dc;
		HGLRC _context;
	};
}
