#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "ASystem.h"

class ARenderSystem : public ASystem
{
public:
	virtual void Render(sf::RenderWindow& window) = 0;
};

