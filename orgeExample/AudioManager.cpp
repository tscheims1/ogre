#include "AudioManager.h"

AudioManager::AudioManager()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
			fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
	}
	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16;
	int audio_channels = 2;
	int audio_buffers = 4096;
 
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError());
		exit(1);
	}

	sounds["background"] = Mix_LoadWAV("sound.wav");
	sounds["shot1"] = Mix_LoadWAV("shot1.wav");
}
void AudioManager::play(std::string soundName)
{
	int channel =0;
	channel = Mix_PlayChannel(-1, sounds[soundName], 0);
	if(channel == -1) {
		fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
	}
}
AudioManager& AudioManager::getInstance()
{
	static AudioManager instance = AudioManager();
	return instance;
}