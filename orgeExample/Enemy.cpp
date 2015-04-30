#include "Enemy.h"

Enemy::Enemy(Ogre::SceneManager** sceneManager,Ogre::Vector3 position)
{
	mEntity = (*sceneManager)->createEntity("RZR-002.mesh");
	mNode = (*sceneManager)->getRootSceneNode()->createChildSceneNode();
	mSceneManagerPtr = sceneManager;

	mNode->setPosition(position);
	mNode->yaw(Ogre::Degree(-180));

	//mNode->pitch(Ogre::Degree(90));
	mNode->attachObject(mEntity);
	mNode->showBoundingBox(true);
}
void Enemy::die()
{
	mNode->detachAllObjects();
	(*mSceneManagerPtr)->destroySceneNode(mNode);
}
void Enemy::update(Ogre::Real deltaTime)
{

}