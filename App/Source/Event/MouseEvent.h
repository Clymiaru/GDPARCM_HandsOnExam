#pragma once
#include "Event/Event.h"
#include <SFML/Graphics.hpp>
#include <string>

class MouseButtonEvent : public Event
{
public:
	sf::Mouse::Button GetMouseButton() const;
protected:
	explicit MouseButtonEvent(sf::Event::MouseButtonEvent event);
	sf::Mouse::Button m_Button;
	int m_MouseX;
	int m_MouseY;
};

class MouseMoveEvent final : public Event
{
public:
	explicit MouseMoveEvent(sf::Event::MouseMoveEvent event);
	int GetX() const;
	int GetY() const;
	String ToString() const override;
	EVENT_CLASS_TYPE(MouseMoved)
private:
	int m_MouseX;
	int m_MouseY;
};

class MouseScrolledEvent final : public Event
{
public:
	MouseScrolledEvent(sf::Event::MouseWheelScrollEvent event);
	float GetXOffset() const;
	float GetYOffset() const;
	String ToString() const override;
	EVENT_CLASS_TYPE(MouseScrolled)
private:
	float m_XOffset;
	float m_YOffset;
};

class MouseButtonPressedEvent final : public MouseButtonEvent
{
public:
	explicit MouseButtonPressedEvent(sf::Event::MouseButtonEvent mouse);
	String ToString() const override;
	int GetX() const;
	int GetY() const;
	EVENT_CLASS_TYPE(MouseButtonPressed)
};

class MouseButtonReleasedEvent final : public MouseButtonEvent
{
public:
	explicit MouseButtonReleasedEvent(sf::Event::MouseButtonEvent button);
	String ToString() const override;
	EVENT_CLASS_TYPE(MouseButtonReleased)
};
