#include "pch.h"
#include "Thread.h"
#include <thread>

Thread::Thread()
{
}

void Thread::Sleep(const float timeInSeconds)
{
	using namespace std::chrono;
	const auto sleepDuration = seconds{static_cast<long int>(timeInSeconds)};
	std::this_thread::sleep_for(sleepDuration);
}

void Thread::Start()
{
	std::thread(&Thread::Run, this).detach();
}
