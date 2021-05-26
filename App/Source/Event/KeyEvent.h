#pragma once
#include "Event/Event.h"
#include <string>
#include <SFML/Graphics.hpp>

class KeyEvent : public Event
{
public:
	sf::Keyboard::Key GetKeyCode() const;
protected:
	explicit KeyEvent(sf::Keyboard::Key keycode);
	sf::Keyboard::Key m_KeyCode;
};

class KeyPressedEvent final: public KeyEvent
{
public:
	explicit KeyPressedEvent(sf::Keyboard::Key keycode);
	std::string ToString() const override;
	EVENT_CLASS_TYPE(KeyPressed)
};

class KeyReleasedEvent final: public KeyEvent
{
public:
	explicit KeyReleasedEvent(sf::Keyboard::Key keycode);
	std::string ToString() const override;
	EVENT_CLASS_TYPE(KeyReleased)
};
