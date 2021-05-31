#pragma once
#include <mutex>

#include "IconCodex.h"
#include <semaphore>
struct SharedIconCodexData
{
	IconCodex* IconStorage;
	std::counting_semaphore<1>* IconCodexLock;
	std::counting_semaphore<1>* DeleterIsRunning;
	std::counting_semaphore<4>* SearcherCountLock;
	int SearcherCount;

	explicit SharedIconCodexData(IconCodex* iconCodex) :
		IconStorage{iconCodex},
		IconCodexLock{new std::counting_semaphore<1>(1)},
		DeleterIsRunning{new std::counting_semaphore<1>(1)},
		SearcherCountLock{new std::counting_semaphore<4>(4)},
		SearcherCount{0}
	{
	}
};
