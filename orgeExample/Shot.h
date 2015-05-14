#ifndef __SHOT_H__
#define __SHOT_H__
#include "Sprite.h"

class Shot : public Sprite
{
private:
	Ogre::Vector3 mDirection;
public:
	Shot(Ogre::SceneManager** sceneManagerPtr,Ogre::Vector3 position,Ogre::Vector3 direction);
	void die();
	void fire();
	void update(Ogre::Real deltaTime);
};
#endif