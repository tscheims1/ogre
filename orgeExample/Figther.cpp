#include "Fighter.h"
Fighter::Fighter(Ogre::SceneManager* sceneManager,Ogre::Vector3 position)
{

	shotCount = 0;
	this->sceneManager = sceneManager;
	entity = sceneManager->createEntity("RZR-002.mesh");
	root = sceneManager->getRootSceneNode();
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
	Ogre::Entity* shot = sceneManager->createEntity("shot"+std::to_string(shots.size()),"RZR-002.mesh");

	Ogre::Vector3 shotPos = node->getPosition();
	shotPos.z += 2;
	Ogre::SceneNode* shotNode = root->createChildSceneNode(shotPos);
	shotNode->scale(0.2,0.2,0.2);
	shotNode->yaw(Ogre::Degree(-180));
	shotNode->pitch(Ogre::Degree(-90));
	shotNode->attachObject(shot);

	
	shots.push_back(shotNode);

}
void Fighter::update(Ogre::Real deltaTime)
{

}