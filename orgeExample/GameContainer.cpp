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
	for(std::vector<Sprite*>::iterator it = mElements.begin(); it != mElements.end();++it)
		(*it)->update(deltaTime);
	mFighter->update(deltaTime);
}
void GameContainer::manageCollision()
{

	for(std::vector<Sprite*>::iterator it = mElements.begin();it != mElements.end();)
	{
		mFighter->checkCollsion((*it));
		if(mFighter->checkEnemyShot((*it)))
		{
			delete (*it);
			it = mElements.erase(it);
		}
		else
			++it;
	}
}