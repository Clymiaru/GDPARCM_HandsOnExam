#pragma once
#include <functional>

#include "AComponent.h"
#include "TextComponent.h"

class LoadingIndicatorComponent final: public AComponent
{
public:
	LoadingIndicatorComponent(Entity& owner,
							  TextComponent& textComponent,
							  std::function<void()> onLoadingComplete);
	
	MAKE_COMPONENT(LoadingIndicatorComponent)

	void UpdateProgress(int currentProgress);
	void UpdateMaxProgress(int maxProgress);
	int GetCurrentProgress() const;
	int GetMaxExpectedProgress() const;

	TextComponent& GetTextComponent() const;

	void ExecuteOnComplete();
private:
	TextComponent& m_TextComponent;
	int m_CurrentProgress;
	int m_MaxExpectedLoadedAssets;
	std::function<void()> m_OnLoadingComplete;
	bool m_IsLoadingComplete;
};
