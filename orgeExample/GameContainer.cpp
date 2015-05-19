#include "GameContainer.h"
#include "AudioManager.h"

GameContainer::GameContainer(Fighter* fighter)
{
	mFighter = fighter;
	AudioManager::getInstance().play("background");
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
			//avoid enemy collisions
			bool update = true;
			for(std::vector<Sprite*>::iterator it2 = mElements.begin(); it2 !=mElements.end();++it2)
			{
				//don't check own collision
				if((*it) == (*it2))
					continue;
				if((*it)->checkBeforeCollide((*it2),1))
					update = false;

			}
			if(update)
				(*it)->update(deltaTime);
			++it;
		}
	}
	mFighter->update(deltaTime);
}