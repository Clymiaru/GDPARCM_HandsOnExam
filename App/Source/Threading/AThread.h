#pragma once
#include <chrono>

class AThread
{
public:
	explicit AThread();
	virtual ~AThread() = default;

	static void Sleep(const std::chrono::milliseconds milliseconds);

	void Start();
	virtual void Run() = 0;
};
