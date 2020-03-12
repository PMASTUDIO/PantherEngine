#pragma once
#include <Panther.h>
#include "GamePlayScreen.h"

class App : public BookEngine::IGame
{
public:
	App();
	~App();

	virtual void OnInit() override;
	virtual void OnExit() override;
	virtual void AddScreens() override;

private:
	std::unique_ptr<GameplayScreen> m_gameplayScreen = nullptr;
};
