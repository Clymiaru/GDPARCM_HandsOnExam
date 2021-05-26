#pragma once
class IWorkerAction
{
public:
	virtual ~IWorkerAction() = default;
	virtual void OnExecuteAction() = 0;
};
