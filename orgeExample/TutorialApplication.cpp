/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _ 
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/                              
      Tutorial Framework
      http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#include "TutorialApplication.h"
#include "SDL.h"
#include "SDL_audio.h"
#include "SDL_mixer.h"
//#include "SDL_audio.h"
//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
	

}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
	//audio
	/*
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

	Mix_Chunk *sound = NULL;
	sound = Mix_LoadWAV("C:\\Users\\James\\Documents\\Visual Studio 2012\\Projects\\orgeExample\\Debug\\sound.wav");
	int channel;
 
	channel = Mix_PlayChannel(-1, sound, 0);
	if(channel == -1) {
		fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
	}*/




	Ogre::Vector3 position = Ogre::Vector3(-30, 0,-100);
	fighter = new Fighter(&mSceneMgr,&mCamera,position);
	mGameContainer = new GameContainer(fighter);
	
	position = Ogre::Vector3(0, 0, -300);
	mGameContainer = new GameContainer(fighter);
	mGameContainer->add(new Enemy(&mSceneMgr,position,fighter->getPosition()));

	position = Ogre::Vector3(-30, 0, -200);
	mGameContainer->add(new Enemy(&mSceneMgr,position,fighter->getPosition()));


	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5,0.5,0.5));
		
	Ogre::Light* light = mSceneMgr->createLight("MainLight");
	light->setPosition(300, 100, 300);
}

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
		
	


        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
