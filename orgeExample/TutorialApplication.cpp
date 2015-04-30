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
    // create your scene here :)
	//mCamera->setPosition(0, 47, 400);


	Ogre::Vector3 position = Ogre::Vector3(-30, 0,-100);
	fighter = new Fighter(&mSceneMgr,&mCamera,position);
	mGameContainer = new GameContainer(fighter);
	
	position = Ogre::Vector3(0, 0, -300);
	mGameContainer = new GameContainer(fighter);
	mGameContainer->add(new Enemy(&mSceneMgr,position));

	/*Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

	Ogre::MeshManager::getSingleton().createPlane(
		  "ground",
		  Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		  plane, 
		  1500, 1500, 20, 20, 
		  true, 
		  1, 5, 5, 
		  Ogre::Vector3::UNIT_Z);

	Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	*/


	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5,0.5,0.5));
	Ogre::Entity* ogreEntity = mSceneMgr->createEntity("ogrehead.mesh");
	Ogre::Entity* ogreEntity2 = mSceneMgr->createEntity("ogrehead.mesh");
	 
	

	Ogre::SceneNode* ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();

	
	//Ogre::SceneNode* ogreNode2 = ogreNode->createChildSceneNode(Ogre::Vector3(84, 48, 0));
	Ogre::SceneNode* ogreNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	//Ogre::SceneNode* ogreNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode("player");


	ogreNode->attachObject(ogreEntity);
	///ogreNode2->attachObject(ogreEntity2);
	
	
	Ogre::Entity* ogreEntity3 = mSceneMgr->createEntity("ogrehead.mesh");
 
	ogreNode3->setPosition(0, 0, 104);
	ogreNode3->attachObject(ogreEntity3);

	Ogre::Entity* ogreEntity4 = mSceneMgr->createEntity("RZR-002.mesh");
 


	
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
