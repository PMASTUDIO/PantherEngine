#include "AudioManager.h"
#include "Exception.h"

namespace BookEngine {
	AudioManager::AudioManager()
	{
	}
	AudioManager::~AudioManager()
	{
		Destroy();
	}
	void AudioManager::Init()
	{
		if (m_isInitialized)
			throw Exception("Audio manager is already initialized");

		if (Mix_Init(MIX_INIT_OGG || MIX_INIT_MP3) == -1)
			throw Exception("SDL_Mixed could not be initialized! Error: " + std::string(Mix_GetError()));

		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);

		m_isInitialized = true;
	}
	void AudioManager::Destroy()
	{
		if (m_isInitialized) {
			m_isInitialized = false;
			
			for (auto& iter : m_effectList)
				Mix_FreeChunk(iter.second);

			for (auto& iter : m_musicList)
				Mix_FreeMusic(iter.second);

			Mix_CloseAudio();
			Mix_Quit();
		}
	}
	SoundEffect AudioManager::LoadSoundEffect(const std::string& filepath)
	{
		SoundEffect effect;

		auto iter = m_effectList.find(filepath);
		if (iter == m_effectList.end()) {
			Mix_Chunk* chunk = Mix_LoadWAV(filepath.c_str());
			if (chunk == nullptr)
				throw Exception("Mix LoadWAV Error: " + std::string(Mix_GetError()));

			effect.m_chunk = chunk;
			m_effectList[filepath] = chunk;
		}
		else {
			effect.m_chunk = iter->second;
		}
		return effect;
	}
	Music AudioManager::LoadMusicEffect(const std::string& filepath)
	{
		Music music;

		auto iter = m_musicList.find(filepath);
		if (iter == m_musicList.end()) {
			Mix_Music* chunk = Mix_LoadMUS(filepath.c_str());
			if (chunk == nullptr)
				throw Exception("Mix LoadMUS Error: " + std::string(Mix_GetError()));

			music.m_music = chunk;
			m_musicList[filepath] = chunk;
		}
		else {
			music.m_music = iter->second;
		}
		return music;
	}
	void SoundEffect::Play(int numOfLoops)
	{
		if (Mix_PlayChannel(-1, m_chunk, numOfLoops) == -1)
			if (Mix_PlayChannel(0, m_chunk, numOfLoops) == -1)
				throw Exception("Mix_PlayChannel Error: " + std::string(Mix_GetError()));
	}
	void Music::Play(int numOfLoops)
	{
		if (Mix_PlayMusic(m_music, numOfLoops) == -1)
			throw Exception("Mix_PlayMusic Error: " + std::string(Mix_GetError()));
	}
}
