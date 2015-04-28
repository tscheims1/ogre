#include "Shot.h"

Shot::Shot(Ogre::SceneManager** sceneManagerPtr,Ogre::Vector3 position)
{
	this->sceneManagerPtr = sceneManagerPtr;
	entity = (*sceneManagerPtr)->createEntity("RZR-002.mesh");

	node= (*sceneManagerPtr)->getRootSceneNode()->createChildSceneNode(position);


	node->scale(0.2f,0.2f,0.2f);
	node->yaw(Ogre::Degree(-180));
	node->pitch(Ogre::Degree(-90));
	node->attachObject(entity);
}
void Shot::update(Ogre::Real deltaTime)
{
	Ogre::Vector3 pos = Ogre::Vector3(0,4*GAME_UNIT,0) * deltaTime;

	node->setPosition(node->getPosition()+pos);
}
void Shot::die()
{
	node->detachAllObjects();
	(*sceneManagerPtr)->destroySceneNode(node);
}