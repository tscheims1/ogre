#ifndef __FIGHTER_H__
#define __FIGHTER_H__
#include "Sprite.h"

class Fighter : public Sprite
{
protected:
	Ogre::Entity* shot;
	std::vector<Ogre::SceneNode*>shots;
	int shotCount;
public:
	Fighter(Ogre::SceneManager* sceneManager,Ogre::Vector3 position);
	void die();
	void fire();
	void update(Ogre::Real deltaTime);

};
#endif