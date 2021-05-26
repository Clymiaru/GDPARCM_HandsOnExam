#include "pch.h"
#include "Random.h"

namespace Utils
{
	std::random_device Random::m_Generator;

	int Random::GetInt(const int min,
	                   const int max)
	{
		const std::uniform_int_distribution<int> distribution(min, max);
		return distribution(m_Generator);
	}

	float Random::GetFloat(const float min,
	                       const float max)
	{
		const std::uniform_real_distribution<float> distribution(min, max);
		return distribution(m_Generator);
	}

	bool Random::GetBool()
	{
		const std::uniform_int_distribution<int> distribution(0, 1);
		return distribution(m_Generator);
	}
}
