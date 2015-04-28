#include "Fighter.h"
Fighter::Fighter(Ogre::SceneManager** sceneManagerPtr,Ogre::Camera** camera,Ogre::Vector3 position)
{

	this->cameraPtr = camera;
	this->sceneManagerPtr = sceneManagerPtr;
	entity = (*this->sceneManagerPtr)->createEntity("RZR-002.mesh");
	root =	 (*this->sceneManagerPtr)->getRootSceneNode();
	node = root->createChildSceneNode("fighter");

	
	node->setPosition(position);
	node->yaw(Ogre::Degree(-180));

	node->pitch(Ogre::Degree(-90));
	node->attachObject(entity);
	node->showBoundingBox(true);
}
void Fighter::die()
{
	

}
void Fighter::fire()
{
	Ogre::Vector3 shotPos = node->getPosition();
	Shot* shotPtr = new Shot(sceneManagerPtr,shotPos);	
	shots.push_back(shotPtr);

}
void Fighter::update(Ogre::Real deltaTime)
{
	for(std::vector<Shot*>::iterator it = shots.begin(); it != shots.end();)
	{
		(*it)->update(deltaTime);
		/**
		@see	http://www.ogre3d.org/forums/viewtopic.php?t=2519
				http://de.wikipedia.org/wiki/Projektionsmatrix
		 */
		Ogre::Vector3 hcpPos = (*cameraPtr)->getProjectionMatrix()*(*cameraPtr)->getViewMatrix()*node->getPosition();

		if ((hcpPos.x < -1.0f) || 
		  (hcpPos.x > 1.0f) ||
		  (hcpPos.y < -1.0f) || 
		  (hcpPos.y > 1.0f))
		{
			(*it)->die();
			delete (*it);
			it = shots.erase(it);
		}
		else
		{
			++it;
		}

		
	}
}