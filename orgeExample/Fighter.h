#ifndef __FIGHTER_H__
#define __FIGHTER_H__
#include "Sprite.h"

class Fighter : Sprite
{

public:
	Fighter();
	void move(Ogre::Vector3 moveVector);
	void init(Ogre::SceneManager* sceneManager);




};
#endif