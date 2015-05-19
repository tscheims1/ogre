#ifndef __AUDIOMANAGER_H__
#define  __AUDIOMANAGER_H__

#include "SDL.h"
#include "SDL_audio.h"
#include "SDL_mixer.h"

class AudioManager
{
private:
	std::map<std::string,Mix_Chunk*> sounds;
	AudioManager();
	AudioManager(AudioManager const&);              // Don't Implement
    void operator=(AudioManager const&);			// Don't implement

public:
	
	void play(std::string soundName);
	static AudioManager& getInstance();
};
#endif