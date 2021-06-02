#pragma once
#include <chrono>

namespace Utils
{
	class Stopwatch final
	{
	public:
		Stopwatch();
		~Stopwatch();
	private:
		std::chrono::time_point<std::chrono::steady_clock> m_Start;
		std::chrono::time_point<std::chrono::steady_clock> m_End;
		std::chrono::duration<float, std::micro> m_Duration;
		std::chrono::steady_clock m_HighResClock;
	};
}
