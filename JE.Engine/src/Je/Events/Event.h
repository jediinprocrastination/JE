#pragma once

#include "Jepch.h"

namespace Je
{
	class Event
	{
	public:
		virtual const char* GetName() const = 0;
	};

	class CloseEvent : public Event
	{
		inline const char* GetName() { return "Close"; }
	};
}
