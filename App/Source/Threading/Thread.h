#pragma once

class Thread
{
public:
	explicit Thread();
	virtual ~Thread() = default;

	static void Sleep(float timeInSeconds);

	void Start();
	virtual void Run() = 0;
};
