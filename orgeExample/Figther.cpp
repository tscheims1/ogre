#include "Fighter.h"
Fighter::Fighter(){}
void Fighter::init(Ogre::SceneManager* sceneManager)
{
	entity = sceneManager->createEntity("RZR-002.mesh");
	node = sceneManager->getRootSceneNode()->createChildSceneNode("fighter");


	node->setPosition(-84, 48, 0);
	node->yaw(Ogre::Degree(-180));
	node->setScale(3,3,3);
	node->pitch(Ogre::Degree(-90));
	node->attachObject(entity);
}
void Fighter::move(Ogre::Vector3 moveVector)
{
	node->translate(moveVector,Ogre::Node::TS_LOCAL);
}
