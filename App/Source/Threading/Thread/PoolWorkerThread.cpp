#include "pch.h"
#include "PoolWorkerThread.h"

PoolWorkerThread::PoolWorkerThread(Uint64 id,
								   IOnCompleteAction* onCompleteAction) :
	m_ID{id},
	m_Action{nullptr},
	m_OnComplete{onCompleteAction}
{
}

Uint64 PoolWorkerThread::GetThreadID() const
{
	return m_ID;
}

void PoolWorkerThread::ScheduleAction(IWorkerAction* workerAction)
{
	m_Action = workerAction;
}

void PoolWorkerThread::Run()
{
	if (m_Action != nullptr && m_OnComplete != nullptr)
	{
		m_Action->OnExecuteAction();
		m_OnComplete->OnCompleteAction(m_ID);
	}
}
