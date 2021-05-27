#pragma once
#include <mutex>

#include "IconCodex.h"

struct SharedIconCodexData
{
	std::mutex* IconCodexMutex;
	IconCodex* IconCodex;
};
