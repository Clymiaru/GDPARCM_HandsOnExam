#include "pch.h"
#include "MouseEvent.h"

String mouseButtonToString(sf::Mouse::Button mouseButton)
{
	switch (mouseButton)
	{
		case sf::Mouse::Left:
			return STRINGIFY(Left);
		case sf::Mouse::Right:
			return STRINGIFY(Right);
		case sf::Mouse::Middle:
			return STRINGIFY(Middle);
		case sf::Mouse::XButton1:
			return STRINGIFY(XButton1);
		case sf::Mouse::XButton2:
			return STRINGIFY(XButton2);
		default:
			return STRINGIFY(Unknown);
	}
}

sf::Mouse::Button MouseButtonEvent::GetMouseButton() const
{
	return m_Button;
}

MouseButtonEvent::MouseButtonEvent(const sf::Event::MouseButtonEvent event):
	m_Button(event.button),
	m_MouseX(event.x),
	m_MouseY(event.y)
{
}

MouseMoveEvent::MouseMoveEvent(const sf::Event::MouseMoveEvent event):
	m_MouseX(event.x),
	m_MouseY(event.y)
{
}

int MouseMoveEvent::GetX() const
{
	return m_MouseX;
}

int MouseMoveEvent::GetY() const
{
	return m_MouseY;
}

String MouseMoveEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseMoveEvent: " << m_MouseX << ", " << m_MouseY;
	return ss.str();
}

MouseScrolledEvent::MouseScrolledEvent(const sf::Event::MouseWheelScrollEvent event):
	m_XOffset(event.x * event.delta),
	m_YOffset(event.y * event.delta)
{
}

float MouseScrolledEvent::GetXOffset() const
{
	return m_XOffset;
}

float MouseScrolledEvent::GetYOffset() const
{
	return m_YOffset;
}

String MouseScrolledEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
	return ss.str();
}

MouseButtonPressedEvent::MouseButtonPressedEvent(const sf::Event::MouseButtonEvent mouse):
	MouseButtonEvent(mouse)
{
}

String MouseButtonPressedEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseButtonPressedEvent: " << mouseButtonToString(m_Button) << "(" << m_MouseX << ", " << m_MouseY << ")";
	return ss.str();
}

int MouseButtonPressedEvent::GetX() const
{
	return m_MouseX;
}

int MouseButtonPressedEvent::GetY() const
{
	return m_MouseY;
}

MouseButtonReleasedEvent::MouseButtonReleasedEvent(const sf::Event::MouseButtonEvent button):
	MouseButtonEvent(button)
{
}

String MouseButtonReleasedEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseButtonReleasedEvent: " << mouseButtonToString(m_Button);
	return ss.str();
}
