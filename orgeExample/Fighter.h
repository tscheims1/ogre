#ifndef __FIGHTER_H__
#define __FIGHTER_H__
#include "Sprite.h"
#include "Shot.h"

class Fighter : public Sprite
{
protected:
	std::vector<Shot*>mShots;
	Ogre::Camera** mCameraPtr;
	int shotCount;
public:
	Fighter::Fighter(Ogre::SceneManager** sceneManagerPtr,Ogre::Camera** cameraPtr,Ogre::Vector3 position);
	void die();
	void fire();
	void update(Ogre::Real deltaTime);
	bool checkEnemyShot(Sprite* enemy);

};
#endif