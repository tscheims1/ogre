#ifndef __SHOT_H__
#define __SHOT_H__
#include "Sprite.h"

class Shot : public Sprite
{
public:
	Shot(Ogre::SceneManager** sceneManagerPtr,Ogre::Vector3 position);
	void die();
	void fire();
	void update(Ogre::Real deltaTime);
};
#endif