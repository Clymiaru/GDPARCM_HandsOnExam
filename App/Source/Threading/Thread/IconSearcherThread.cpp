#include "pch.h"
#include "IconSearcherThread.h"

IconSearcherThread::IconSearcherThread(SharedIconListData& sharedIconListData) :
	m_SharedIconListData{sharedIconListData},
	m_SelectedIcon{nullptr}
{
}

void IconSearcherThread::Run()
{
	m_SharedIconListData.Mutex->lock();
	m_SelectedIcon = m_SharedIconListData.IconList[0];
	INFO_LOG(SearcherIconThread, "Select Icon 0");
	m_SharedIconListData.Mutex->unlock();

	Sleep(0.2f);
}
