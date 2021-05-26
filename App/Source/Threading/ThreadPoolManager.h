#pragma once
#include "IWorkerAction.h"

#include "Thread/ThreadPool.h"

class ThreadPoolManager final
{
public:
	static ThreadPoolManager& GetInstance();
	~ThreadPoolManager();
	
	ThreadPoolManager(const ThreadPoolManager& other) = delete;
	ThreadPoolManager(ThreadPoolManager&& other) noexcept = delete;
	auto operator=(const ThreadPoolManager& other) -> ThreadPoolManager& = delete;
	auto operator=(ThreadPoolManager&& other) noexcept -> ThreadPoolManager& = delete;

	void StartThreadPool(StringRef threadPoolName, Uint64 maxWorkers);
	void ScheduleThreadPoolTask(StringRef threadPoolName, IWorkerAction* task);
	void StopThreadPool(StringRef threadPoolName);
private:
	ThreadPoolManager();
	HashTable<String, ThreadPool*> m_ThreadPoolList;
};
