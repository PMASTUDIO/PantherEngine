#include "GameplayScreen.h"
#include <iostream>
#include <Panther.h>


GameplayScreen::GameplayScreen()
{
}


GameplayScreen::~GameplayScreen()
{
}

void GameplayScreen::Build()
{
}

void GameplayScreen::Destroy()
{
}

void GameplayScreen::OnEntry()
{
	std::cout << "OnEntry\n";
	m_AudioManager.Init();
	m_bgMusic = m_AudioManager.LoadMusicEffect("Audio/bensound-epic.mp3");
	m_bgMusic.Play();
}

void GameplayScreen::OnExit()
{
	m_bgMusic.Stop();
	m_AudioManager.Destroy();
}

void GameplayScreen::Update()
{
	std::cout << "Update\n";
	CheckInput();
}

void GameplayScreen::Draw()
{
	std::cout << "Draw\n";
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

int GameplayScreen::GetNextScreenIndex() const
{
	return SCREENINDEX_NO_SCREEN;
}

int GameplayScreen::GetPreviousScreenIndex() const
{
	return SCREENINDEX_NO_SCREEN;
}

void GameplayScreen::CheckInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		m_game->OnSDLEvent(event);
	}
}
