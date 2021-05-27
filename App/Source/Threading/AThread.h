#pragma once

class AThread
{
public:
	explicit AThread();
	virtual ~AThread() = default;

	static void Sleep(float timeInSeconds);

	void Start();
	virtual void Run() = 0;
};
