#include "GameContainer.h"

GameContainer::GameContainer(Fighter* fighter)
{
	mFighter = fighter;
}
void GameContainer::add(Sprite* sprite)
{
	mElements.push_back(sprite);
}
void GameContainer::update(Ogre::Real deltaTime)
{
	for(std::vector<Sprite*>::iterator it = mElements.begin(); it != mElements.end();)
	{
		if(mFighter->checkCollsion((*it)))
		{
			//mFighter->die();
			//delete (mFight9er);
			++it;
		}
		else if(mFighter->checkEnemyShot((*it)))
		{
			delete (*it);
			it = mElements.erase(it);
		}
		else
		{
			(*it)->update(deltaTime);
			++it;
		}
	}
	mFighter->update(deltaTime);
}