#pragma once

class IOnCompleteAction
{
public:
	virtual ~IOnCompleteAction() = default;
	virtual void OnCompleteAction(Uint64 threadID) = 0;
};
