#pragma once
#include "Threading/IOnCompleteAction.h"
#include "Threading/IWorkerAction.h"
#include "Threading/Thread.h"

class PoolWorkerThread final : public Thread
{
public:
	PoolWorkerThread(Uint64 id,
					 IOnCompleteAction* onCompleteAction);
	
	Uint64 GetThreadID() const;

	void ScheduleAction(IWorkerAction* workerAction);

protected:
	void Run() override;

	Uint64 m_ID;
	IWorkerAction* m_Action;
	IOnCompleteAction* m_OnComplete;
};
