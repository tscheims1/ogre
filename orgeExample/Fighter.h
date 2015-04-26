#ifndef __FIGHTER_H__
#define __FIGHTER_H__
#include "Sprite.h"

class Fighter : public Sprite
{

public:
	Fighter(Ogre::SceneManager* sceneManager,Ogre::Vector3 position);

};
#endif