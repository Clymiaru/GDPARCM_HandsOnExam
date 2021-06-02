#pragma once
#include <mutex>

#include "IconCodex.h"
#include <semaphore>
struct SharedIconCodexData
{
	IconCodex* IconStorage;
	std::counting_semaphore<1>* IconCodexLock;
	std::counting_semaphore<1>* DeleterIsRunningLock;
	std::counting_semaphore<1>* InserterInProgressLock;
	std::counting_semaphore<1>* SearcherCountLock;
	std::counting_semaphore<1>* InserterCountLock;
	std::atomic_int SearcherCount;
	std::atomic_int InserterCount;

	explicit SharedIconCodexData(IconCodex* iconCodex) :
		IconStorage{iconCodex},
		IconCodexLock{new std::counting_semaphore<1>(1)},
		DeleterIsRunningLock{new std::counting_semaphore<1>(1)},
		InserterInProgressLock{new std::counting_semaphore<1>(1)},
		SearcherCountLock{new std::counting_semaphore<1>(1)},
		InserterCountLock{new std::counting_semaphore<1>(1)},
		SearcherCount{0},
		InserterCount{0}
	{
	}
};
