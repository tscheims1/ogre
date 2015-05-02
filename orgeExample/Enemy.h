#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "Sprite.h"

class Enemy : public Sprite
{
protected:
	const Ogre::Vector3* mTargetPosition;

public:
	Enemy(Ogre::SceneManager** sceneManager,Ogre::Vector3 position,const Ogre::Vector3* targetPosition);
	void die();
	void update(Ogre::Real deltaTime);
		 
};
#endif