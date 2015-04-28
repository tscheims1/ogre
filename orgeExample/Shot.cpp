#include "Shot.h"

Shot::Shot(Ogre::SceneManager** sceneManagerPtr,Ogre::Vector3 position)
{
	mSceneManagerPtr = sceneManagerPtr;
	mEntity = (*sceneManagerPtr)->createEntity("RZR-002.mesh");

	mNode= (*sceneManagerPtr)->getRootSceneNode()->createChildSceneNode(position);


	mNode->scale(0.2f,0.2f,0.2f);
	mNode->yaw(Ogre::Degree(-180));
	mNode->pitch(Ogre::Degree(-90));
	mNode->attachObject(mEntity);
}
void Shot::update(Ogre::Real deltaTime)
{
	Ogre::Vector3 pos = Ogre::Vector3(0,4*GAME_UNIT,0) * deltaTime;

	mNode->setPosition(mNode->getPosition()+pos);
}
void Shot::die()
{
	mNode->detachAllObjects();
	(*mSceneManagerPtr)->destroySceneNode(mNode);
}