#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "Sprite.h"

class Enemy : public Sprite
{
public:
	Enemy(Ogre::SceneManager** sceneManager,Ogre::Vector3 position);
	void die();
	void update(Ogre::Real deltaTime);
		 
};
#endif