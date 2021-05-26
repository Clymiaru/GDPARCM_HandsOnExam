#pragma once
#include "PoolWorkerThread.h"

#include "Threading/Thread.h"

class ThreadPool final : public Thread, public IOnCompleteAction
{
public:
	ThreadPool(StringRef name, Uint64 maxWorkers);
	~ThreadPool() override;

	void StartScheduler();
	void StopScheduler();
	void ScheduleTask(IWorkerAction* scheduledAction);

protected:
	void Run() override;
	void OnCompleteAction(Uint64 threadID) override;

private:
	String m_Name;
	Uint64 m_MaxWorkers;
	bool m_IsRunning;

	HashTable<Uint64, PoolWorkerThread*> m_ActiveThreadMap;
	Queue<PoolWorkerThread*> m_InactiveThreadQueue;
	Queue<IWorkerAction*> m_PendingActionQueue;
};
