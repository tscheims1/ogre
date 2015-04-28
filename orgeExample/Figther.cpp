#include "Fighter.h"
Fighter::Fighter(Ogre::SceneManager** sceneManagerPtr,Ogre::Camera** cameraPtr,Ogre::Vector3 position)
{

	mCameraPtr = cameraPtr;
	mSceneManagerPtr = sceneManagerPtr;
	mEntity = (*mSceneManagerPtr)->createEntity("RZR-002.mesh");
	mRoot =	 (*mSceneManagerPtr)->getRootSceneNode();
	mNode = mRoot->createChildSceneNode("fighter");

	
	mNode->setPosition(position);
	mNode->yaw(Ogre::Degree(-180));

	mNode->pitch(Ogre::Degree(-90));
	mNode->attachObject(mEntity);
	mNode->showBoundingBox(true);
}
void Fighter::die()
{
	mNode->detachAllObjects();
	(*mSceneManagerPtr)->destroySceneNode(mNode);

}
void Fighter::fire()
{
	Ogre::Vector3 shotPos = mNode->getPosition();
	Shot* shotPtr = new Shot(mSceneManagerPtr,shotPos);	
	mShots.push_back(shotPtr);

}
void Fighter::update(Ogre::Real deltaTime)
{
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