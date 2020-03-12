#include "App.h"
#include <Panther.h>

App::App()
{
}


App::~App()
{
}

void App::OnInit()
{
}

void App::OnExit()
{
}

void App::AddScreens()
{
	m_gameplayScreen = std::make_unique<GameplayScreen>();
	m_screenList->AddScreen(m_gameplayScreen.get()); //get underlining pointer
	m_screenList->SetCurrentScreen(m_gameplayScreen->GetScreenIndex());
}
