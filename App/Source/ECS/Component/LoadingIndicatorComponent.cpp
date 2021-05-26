#include "pch.h"
#include "LoadingIndicatorComponent.h"

LoadingIndicatorComponent::LoadingIndicatorComponent(Entity& owner,
													TextComponent& textComponent,
													std::function<void()> onComplete) :
	AComponent{owner},
	m_TextComponent{textComponent},
	m_CurrentProgress{0},
	m_MaxExpectedLoadedAssets{0},
	m_OnLoadingComplete{onComplete},
	m_IsLoadingComplete{false}
{
}

void LoadingIndicatorComponent::UpdateProgress(int currentProgress)
{
	m_CurrentProgress = currentProgress;
}

void LoadingIndicatorComponent::UpdateMaxProgress(int maxProgress)
{
	m_MaxExpectedLoadedAssets = maxProgress;
}

int LoadingIndicatorComponent::GetCurrentProgress() const
{
	return m_CurrentProgress;
}

int LoadingIndicatorComponent::GetMaxExpectedProgress() const
{
	return m_MaxExpectedLoadedAssets;
}

TextComponent& LoadingIndicatorComponent::GetTextComponent() const
{
	return m_TextComponent;
}

void LoadingIndicatorComponent::ExecuteOnComplete()
{
	if (!m_IsLoadingComplete)
	{
		m_OnLoadingComplete();
		m_IsLoadingComplete = true;
	}
	
}

