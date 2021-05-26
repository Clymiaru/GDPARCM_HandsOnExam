#pragma once
#include "Event.h"

class TestEvent final : public Event
{
public:
	TestEvent() = default;
	EVENT_CLASS_TYPE(Test)
};
