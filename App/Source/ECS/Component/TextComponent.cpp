#include "pch.h"
#include "TextComponent.h"

TextComponent::TextComponent(Entity& owner,
	TransformComponent& transform,
	Font& font,
	Uint fontSize) :
	AComponent{owner},
	m_Font{font},
	m_Transform{transform}
{
	m_Text = new sf::Text("", font.GetData(), fontSize);
}

sf::Text& TextComponent::GetText() const
{
	return *m_Text;
}

void TextComponent::UpdateText(StringRef text) const
{
	m_Text->setString(text);
}

void TextComponent::SetColor(const sf::Color& color) const
{
	m_Text->setFillColor(color);
}

TransformComponent& TextComponent::GetTransform() const
{
	return m_Transform;
}
