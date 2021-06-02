#include "pch.h"
#include "Stopwatch.h"
#include <iostream>

namespace Utils
{
	Stopwatch::Stopwatch():
		m_Start{std::chrono::time_point<std::chrono::steady_clock>()},
		m_End{std::chrono::time_point<std::chrono::steady_clock>()},
		m_Duration{}
	{
		m_Start = std::chrono::steady_clock::now();
	}

	Stopwatch::~Stopwatch()
	{
		m_End      = std::chrono::steady_clock::now();
		m_Duration = m_End - m_Start;
		std::cout << "Duration: " << m_Duration.count() << "us\n";
	}
}
