#include "pch.h"
#include "ThreadPool.h"

ThreadPool::ThreadPool(StringRef name,
					   const Uint64 maxWorkers) :
	m_Name{name},
	m_MaxWorkers{maxWorkers},
	m_IsRunning{false}
{
	for (auto i = 0; i < m_MaxWorkers; i++)
	{
		m_InactiveThreadQueue.push(new PoolWorkerThread(i, this));
	}
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::StartScheduler()
{
	m_IsRunning = true;
	Start();
}

void ThreadPool::StopScheduler()
{
	m_IsRunning = false;
}

void ThreadPool::ScheduleTask(IWorkerAction* scheduledAction)
{
	m_PendingActionQueue.push(scheduledAction);
}

void ThreadPool::Run()
{
	while (m_IsRunning)
	{
		if (!m_PendingActionQueue.empty())
		{
			if (!m_InactiveThreadQueue.empty())
			{
				auto* workerThread       = m_InactiveThreadQueue.front();
				m_InactiveThreadQueue.pop();

				auto workerThreadID      = workerThread->GetThreadID();
				
				const auto pendingAction = m_PendingActionQueue.front();
				m_PendingActionQueue.pop();

				m_ActiveThreadMap[workerThreadID] = workerThread;
				workerThread->ScheduleAction(pendingAction);
				workerThread->Start();
			}
		}
	}
}

void ThreadPool::OnCompleteAction(Uint64 threadID)
{
	if (m_ActiveThreadMap[threadID] != nullptr)
	{
		delete m_ActiveThreadMap[threadID];
		m_ActiveThreadMap.erase(threadID);
		m_InactiveThreadQueue.push(new PoolWorkerThread(threadID, this));
	}
}
