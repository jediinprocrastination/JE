#pragma once

#include "Jepch.h"
#include "Je/Window.h"

namespace Je
{
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
	
	protected:
		virtual void Init(const WindowProperties& properties);
		virtual void Shutdown();
	
	private:

		struct WinData
		{
			std::string Title;
			unsigned int Height, Width;
			bool VSync;
		};

		WinData _data;
	};
}
