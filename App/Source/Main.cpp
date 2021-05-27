#include "pch.h"
#include "BaseRunner.h"

int main()
{
	auto app = BaseRunner({1280, 720},
						  "Hands On Exam");

	app.Run();
}
