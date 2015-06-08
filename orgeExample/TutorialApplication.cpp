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
