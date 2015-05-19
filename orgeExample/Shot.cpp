#include "Shot.h"

Shot::Shot(Ogre::SceneManager** sceneManagerPtr,Ogre::Vector3 position,Ogre::Vector3 direction)
{
	mSceneManagerPtr = sceneManagerPtr;
	mEntity = (*sceneManagerPtr)->createEntity("RZR-002.mesh");
	direction.y = 0;
	mDirection = direction;
	mNode= (*sceneManagerPtr)->getRootSceneNode()->createChildSceneNode(position);

	mNode->scale(0.2f,0.2f,0.2f);
	mNode->attachObject(mEntity);
}
void Shot::update(Ogre::Real deltaTime)
{
	Ogre::Vector3 pos = mDirection * deltaTime*GAME_UNIT*4;

	mNode->setPosition(mNode->getPosition()+pos);
}
void Shot::die()
{
	mNode->detachAllObjects();
	(*mSceneManagerPtr)->destroySceneNode(mNode);
}