#pragma once
#include <Panther.h>

class GameplayScreen : public BookEngine::IScreen
{
public:
	GameplayScreen();
	~GameplayScreen();

	// Inherited via IGameScreen
	virtual void Build() override;

	virtual void Destroy() override;

	virtual void OnEntry() override;

	virtual void OnExit() override;

	virtual void Update() override;

	virtual void Draw() override;

	virtual int GetNextScreenIndex() const override;

	virtual int GetPreviousScreenIndex() const override;

private:
	void CheckInput();
	BookEngine::AudioManager m_AudioManager;
	BookEngine::Music m_bgMusic;
};

