#pragma once
#include "Event/Event.h"
#include <string>
#include <iostream>
#include <sstream>

class WindowResizeEvent final: public Event
{
public:
	WindowResizeEvent(const sf::Event::SizeEvent event) :
		m_Width(event.width),
		m_Height(event.height)
	{
	}

	Uint GetWidth() const
	{
		return m_Width;
	}

	Uint GetHeight() const
	{
		return m_Height;
	}

	String ToString() const override
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
		return ss.str();
	}

	EVENT_CLASS_TYPE(WindowResize)
private:
	Uint m_Width;
	Uint m_Height;
};

class WindowCloseEvent final: public Event
{
public:
	WindowCloseEvent() = default;
	EVENT_CLASS_TYPE(WindowClose)
};

class WindowFocusEvent final: public Event
{
public:
	WindowFocusEvent() = default;
	EVENT_CLASS_TYPE(WindowFocus)
};

class WindowLostFocusEvent final: public Event
{
public:
	WindowLostFocusEvent() = default;
	EVENT_CLASS_TYPE(WindowLostFocus)
};

class WindowMoveEvent final: public Event
{
public:
	WindowMoveEvent() = default;
	EVENT_CLASS_TYPE(WindowMove)
};