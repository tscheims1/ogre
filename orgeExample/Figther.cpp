#include "Fighter.h"
#include "AudioManager.h"
Fighter::Fighter(Ogre::SceneManager** sceneManagerPtr,Ogre::Camera** cameraPtr,Ogre::Vector3 position)
{
	mCurrentPosition = position;

	
	mCameraPtr = cameraPtr;
	mSceneManagerPtr = sceneManagerPtr;
	mEntity = (*mSceneManagerPtr)->createEntity("RZR-002.mesh");
	mRoot =	 (*mSceneManagerPtr)->getRootSceneNode();
	mNode = mRoot->createChildSceneNode("fighter");

	mNode->setDebugDisplayEnabled(true);
	mNode->setPosition(position);
	mNode->yaw(Ogre::Degree(-180));

	mNode->attachObject(mEntity);
	mNode->showBoundingBox(true);
}
void Fighter::die()
{
	/*mNode->detachAllObjects();
	(*mSceneManagerPtr)->destroySceneNode(mNode);*/

}
void Fighter::fire()
{
	if(lastShot.getMilliseconds() > 100)
		lastShot.reset();
	else
		return;

	AudioManager::getInstance().play("shot1");
	

	Ogre::Vector3 shotPos = mNode->getPosition();
	Ogre::Vector3 direction = mNode->getOrientation()*Ogre::Vector3::UNIT_Z;
	Shot* shotPtr = new Shot(mSceneManagerPtr,shotPos,direction.normalisedCopy());	
	mShots.push_back(shotPtr);


}
void Fighter::update(Ogre::Real deltaTime)
{
	Ogre::Vector3 curPos = mNode->getPosition();
	Ogre::Vector3 direction = curPos - mCursorPos;

	Ogre::Vector3 src = mNode->getOrientation() * -Ogre::Vector3::UNIT_Z;
	src.y = 0;                                                   
	direction.y = 0;
	src.normalise();
	direction.normalise();
	
	mNode->setPosition(mNode->getPosition()+mCurrentMoveVector);
	Ogre::Quaternion quat = src.getRotationTo(direction); 

	mNode->rotate(quat);

	/*
	 * Update all shots
	 */
	for(std::vector<Shot*>::iterator it = mShots.begin(); it != mShots.end();)
	{
		(*it)->update(deltaTime);
		/**
		@see	http://www.ogre3d.org/forums/viewtopic.php?t=2519
				http://de.wikipedia.org/wiki/Projektionsmatrix
		 */
		Ogre::Vector3 hcpPos = (*mCameraPtr)->getProjectionMatrix()*(*mCameraPtr)->getViewMatrix()*mNode->getPosition();

		if ((hcpPos.x < -1.0f) || 
		  (hcpPos.x > 1.0f) ||
		  (hcpPos.y < -1.0f) || 
		  (hcpPos.y > 1.0f))
		{
			(*it)->die();
			delete (*it);
			it = mShots.erase(it);
		}
		else
		{
			++it;
		}
	}
	//Update positon for enemies
	mCurrentPosition = mNode->getPosition();
}
bool Fighter::checkEnemyShot(Sprite* enemy)
{
	for(std::vector<Shot*>::iterator it = mShots.begin(); it != mShots.end(); ++it)
	{
		if((*it)->checkCollsion(enemy))
		{
			enemy->die();
			return true;
		}
	}
	return false;
}
const Ogre::Vector3* Fighter::getPosition()
{
	return &mCurrentPosition;
}
void Fighter::setCursorPos(Ogre::Vector3 pos)
{
	mCursorPos = pos;
}