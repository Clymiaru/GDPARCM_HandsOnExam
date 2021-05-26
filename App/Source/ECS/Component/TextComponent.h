#pragma once

#include "AComponent.h"
#include "TransformComponent.h"

#include "AssetManagement/Font/Font.h"

class TextComponent : public AComponent
{
public:
	TextComponent(Entity& owner,
			   	  TransformComponent& transform,
				  Font& font,
				  Uint fontSize);
		
	MAKE_COMPONENT(TextComponent)

	sf::Text& GetText() const;
	void UpdateText(StringRef text) const;
	void SetColor(const sf::Color& color) const;
	TransformComponent& GetTransform() const;

private:
	TransformComponent& m_Transform;
	Font& m_Font;
	sf::Text* m_Text;
};
