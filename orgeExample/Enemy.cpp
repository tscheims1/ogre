#include "Enemy.h"

Enemy::Enemy(Ogre::SceneManager** sceneManager,Ogre::Vector3 position,const Ogre::Vector3* targetPosition)
{

	mTargetPosition = targetPosition;
	mEntity = (*sceneManager)->createEntity("RZR-002.mesh");
	mNode = (*sceneManager)->getRootSceneNode()->createChildSceneNode();
	mSceneManagerPtr = sceneManager;

	mNode->setPosition(position);
	mNode->attachObject(mEntity);
	//mNode->showBoundingBox(true);
}
void Enemy::die()
{
	mNode->detachAllObjects();
	(*mSceneManagerPtr)->destroySceneNode(mNode);
}
void Enemy::update(Ogre::Real deltaTime)
{
	Ogre::Vector3 myPos =mNode->getPosition();

	Ogre::Vector3 direction = (*mTargetPosition)-myPos;
	mCurrentMoveVector = direction;
	direction.y = 0;
	
	Ogre::Vector3 src = mNode->getOrientation() * Ogre::Vector3::UNIT_Z;
	src.y = 0;                                                   
	direction.y = 0;
	src.normalise();
	direction.normalise();
	mNode->setPosition(mNode->getPosition()+direction*2*GAME_UNIT*deltaTime);

	Ogre::Quaternion quat = src.getRotationTo(direction); 

	mNode->rotate(quat);
	OutputDebugStringA(("enemy pos:"+Ogre::StringConverter::toString(mNode->getPosition())+"\n").c_str());

}