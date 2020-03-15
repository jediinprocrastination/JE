#pragma once

#include "Jepch.h"
#include "Event.h"

namespace Je
{
	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float x, float y)
			: m_x(x), m_y(y)
		{
		}

		inline float GetX() { return m_x; }
		inline float GetY() { return m_y; }

		const char* GetName() const override
		{
			return "MouseMove";
		}

		const std::string ToString() override
		{
			std::stringstream s;
			s << "MouseMoveEvent: (x: " << m_x << "y: " << m_y << ")";

			return s.str();
		}

	private:
		float m_x;
		float m_y;
	};
}
