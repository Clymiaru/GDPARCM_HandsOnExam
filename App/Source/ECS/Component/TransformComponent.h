#pragma once
#include <SFML/Graphics/Transformable.hpp>

#include "AComponent.h"

class TransformComponent final : public AComponent
{
public:
	explicit TransformComponent(Entity& owner,
								sf::Transformable initialTransform = sf::Transformable());
	~TransformComponent() override;

	MAKE_COMPONENT(Transform)
	
	void SetPosition(const sf::Vector2f& position);
	const sf::Vector2f& GetPosition() const;

	void Move(const sf::Vector2f& moveVector);

	void SetScale(const sf::Vector2f& scale);
	const sf::Vector2f& GetScale() const;

	void Scale(const sf::Vector2f& scaleVector);

	void SetRotation(float rotation);
	float GetRotation() const;

	void Rotate(float angleInDegrees);

	const sf::Transform& GetRawTransform() const; 
private:
	sf::Transformable m_Transform;
};
