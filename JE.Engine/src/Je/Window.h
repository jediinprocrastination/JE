#pragma once

#include "Jepch.h"
#include "Core.h"
#include "Events/Event.h"

namespace Je
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Height;
		unsigned int Width;

		WindowProperties(
			std::string title		= "Je window",
			unsigned int height = 720, 
			unsigned int width	= 1280)
			
			: Title(title), Height(height), Width(width)
		{
		}
	};

	class JE_API Window
	{
	public:

		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;
		virtual void OnUpdate() = 0;
		virtual unsigned int GetHeight() = 0;
		virtual unsigned int GetWidth() = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		virtual void SetCallback(const EventCallbackFn& callback) = 0;

		static Window* Create(const WindowProperties& properties = WindowProperties());
	};
}
