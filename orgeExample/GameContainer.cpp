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

	for(std::vector<Sprite*>::iterator it = mElements.begin();it != mElements.end(); ++it)
	{
		mFighter->checkCollsion((*it));
		mFighter->checkEnemyShot((*it));
	}
}