#pragma once
#include "ECS/ABehaviorSystem.h"
#include "ECS/Component/FPSCounterComponent.h"

class FPSCounterSystem final : public ABehaviorSystem
{
public:
	FPSCounterSystem();
	~FPSCounterSystem() override;
	
	MAKE_SYSTEM(FPSCounterSystem,
         Behavior,
      FPSCounterComponent,
   m_FPSCounterList)

	void Update(float deltaTime) override;

private:
	List<FPSCounterComponent*> m_FPSCounterList;
};