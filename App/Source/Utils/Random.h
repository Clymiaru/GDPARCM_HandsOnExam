#pragma once
#include <random>

namespace Utils
{
	class Random final
	{
	public:
		static int GetInt(int min,
		                  int max);
		static float GetFloat(float min,
		                      float max);
		static bool GetBool();
	private:
		static std::random_device m_Generator;
	};
}
