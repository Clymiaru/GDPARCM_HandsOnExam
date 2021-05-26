#pragma once
#include "ASystem.h"

#include "Event/Event.h"

class AEventSystem : public ASystem
{
public:
	virtual void ProcessEvent(Event& event) = 0;
};