#pragma once
#include "Threading/AThread.h"

#include <mutex>

#include "Icon.h"

struct SharedIconListData
{
	std::mutex* Mutex;
	List<Icon*>& IconList;
};

class IconSearcherThread final : public AThread
{
public:
	explicit IconSearcherThread(SharedIconListData& sharedIconListData);
	virtual ~IconSearcherThread() = default;
	
	void Run() override;

private:
	SharedIconListData& m_SharedIconListData;
	Icon* m_SelectedIcon;
};
