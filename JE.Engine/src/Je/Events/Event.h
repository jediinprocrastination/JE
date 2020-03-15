#pragma once

#include "Jepch.h"

namespace Je
{
	class Event
	{
	public:
		virtual const char* GetName() const = 0;
		virtual const std::string ToString() { return GetName(); }
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event) : m_event(event)
		{
		}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			return true;
		}

	private:
		Event& m_event;
	};
}
