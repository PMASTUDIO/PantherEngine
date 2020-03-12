#pragma once

#include "SDL/SDL_mixer.h"
#include <string>
#include <map>
#include "..//Core.h"

namespace BookEngine {
	class PTH_API SoundEffect {
	public:
		friend class AudioManager;

		void Play(int numOfLoops = 0); // If -1 it plays forever
	private:
		Mix_Chunk* m_chunk = nullptr;
	};

	class PTH_API Music {
	public:
		friend class AudioManager;

		void Play(int numOfLoops = 0); // If -1 it plays forever

		static void Pause() { Mix_PauseMusic(); }
		static void Stop() { Mix_HaltMusic(); }
		static void Resume() { Mix_ResumeMusic(); }
	private:
		Mix_Music* m_music = nullptr;
	};

	class PTH_API AudioManager {
	public:
		AudioManager();
		~AudioManager();

		void Init();
		void Destroy();

		SoundEffect LoadSoundEffect(const std::string& filepath);
		Music LoadMusicEffect(const std::string& filepath);

	private:
		std::map<std::string, Mix_Chunk*> m_effectList;
		std::map<std::string, Mix_Music*> m_musicList;
		bool m_isInitialized = false;
	};
}