#pragma once
#pragma once
#include <string>

enum class EventType
{
	None = 0,
	// Window
	WindowClose,
	WindowResize,
	WindowFocus,
	WindowLostFocus,
	WindowMove,
	// Key
	KeyPressed,
	KeyReleased,
	//Mouse
	MouseButtonPressed,
	MouseButtonReleased,
	MouseMoved,
	MouseScrolled,
	// CUSTOM
	Test
};

#define EVENT_CLASS_TYPE(type)                                                  \
	static EventType GetStaticType() { return EventType::type; }                \
	virtual EventType GetEventType() const override { return GetStaticType(); } \
	virtual const char* GetName() const override { return #type; }

class Event
{
public:
	virtual ~Event() = default;
	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;

	virtual String ToString() const
	{
		return GetName();
	}
};
