#pragma once

#include "Jepch.h"
#include "Core.h"

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
		virtual ~Window() {}
		virtual void OnUpdate() = 0;
		virtual unsigned int GetHeight() = 0;
		virtual unsigned int GetWidth() = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProperties& properties = WindowProperties());
	};
}
