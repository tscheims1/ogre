#ifndef __GAME_CONTAINER_H__
#define __GAME_CONTAINER_H__
#include "Sprite.h"
#include "Fighter.h"

class GameContainer
{
protected:
	std::vector<Sprite*>mElements;
	Fighter* mFighter;


public:
	void update(Ogre::Real deltaTime);
	GameContainer(Fighter* fighter);
	void add(Sprite* element);
	int numberOfSprites();

};
#endif