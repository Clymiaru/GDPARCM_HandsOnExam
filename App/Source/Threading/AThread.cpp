#include "pch.h"
#include "AThread.h"
#include <thread>

AThread::AThread()
{
}

void AThread::Sleep(const float timeInSeconds)
{
	using namespace std::chrono;
	const auto sleepDuration = seconds{static_cast<long int>(timeInSeconds)};
	std::this_thread::sleep_for(sleepDuration);
}

void AThread::Start()
{
	std::thread(&AThread::Run, this).detach();
}
