#pragma once
#include <iostream>

#ifdef DEBUG

#define PRINT_LOG_TAG(x) "[" << STRINGIFY(x) << "] "
#define ASSERT(expectation, tag, errorMessage)						\
	if(!(expectation))												\
	{																\
		std::cout << PRINT_LOG_TAG(tag) << errorMessage << "\n";	\
		__debugbreak();												\
	}

#define INFO_LOG(tag, message)										\
{																	\
	std::cout << PRINT_LOG_TAG(tag) << message << "\n";				\
}

#else

#define PRINT_LOG_TAG(x)
#define ASSERT(expectation, tag, errorMessage)
#define INFO_LOG(tag, message)

#endif
