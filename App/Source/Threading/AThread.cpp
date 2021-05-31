#include "pch.h"
#include "AThread.h"
#include <thread>

AThread::AThread()
{
}

void AThread::Sleep(const std::chrono::milliseconds milliseconds)
{
	std::this_thread::sleep_for(milliseconds);
}


void AThread::Start()
{
	std::thread(&AThread::Run, this).detach();
}
