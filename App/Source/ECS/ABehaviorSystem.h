#pragma once

#include "ASystem.h"

class ABehaviorSystem : public ASystem
{
public:
	virtual void Update(float deltaTime) = 0;
};
