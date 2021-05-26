#include "pch.h"
#include "ThreadPoolManager.h"

ThreadPoolManager& ThreadPoolManager::GetInstance()
{
	static ThreadPoolManager instance;
	return instance;
}

ThreadPoolManager::~ThreadPoolManager()
{
	for (auto threadPool : m_ThreadPoolList)
	{
		threadPool.second->StopScheduler();
	}
}

void ThreadPoolManager::StartThreadPool(StringRef threadPoolName,
                                        const Uint64 maxWorkers)
{
	if (m_ThreadPoolList.find(threadPoolName) == m_ThreadPoolList.end())
	{
		m_ThreadPoolList[threadPoolName] = new ThreadPool(threadPoolName, maxWorkers);
		m_ThreadPoolList[threadPoolName]->StartScheduler();
	}
	else
	{
		INFO_LOG(ThreadPoolManager, threadPoolName << " has already been added!");
	}
}

void ThreadPoolManager::ScheduleThreadPoolTask(StringRef threadPoolName,
	IWorkerAction* task)
{
	if (m_ThreadPoolList.find(threadPoolName) != m_ThreadPoolList.end())
	{
		m_ThreadPoolList[threadPoolName]->ScheduleTask(task);
	}
	else
	{
		INFO_LOG(ThreadPoolManager, threadPoolName << " does not exist!");
	}
}

void ThreadPoolManager::StopThreadPool(StringRef threadPoolName)
{
	if (m_ThreadPoolList.find(threadPoolName) != m_ThreadPoolList.end())
	{
		m_ThreadPoolList[threadPoolName]->StopScheduler();
	}
	else
	{
		INFO_LOG(ThreadPoolManager, threadPoolName << " does not exist!");
	}
}

ThreadPoolManager::ThreadPoolManager()
{
}
