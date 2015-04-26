#include "Fighter.h"
Fighter::Fighter(Ogre::SceneManager* sceneManager,Ogre::Vector3 position)
{
	entity = sceneManager->createEntity("RZR-002.mesh");
	node = sceneManager->getRootSceneNode()->createChildSceneNode("fighter");

	
	node->setPosition(position);
	node->yaw(Ogre::Degree(-180));

	node->pitch(Ogre::Degree(-90));
	node->attachObject(entity);
	node->showBoundingBox(true);
}
