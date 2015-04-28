#ifndef __SPRITE_H__
#define __SPRITE_H__
class Sprite
{
protected:
	Ogre::Entity* entity;
	Ogre::SceneManager* sceneManager;
	Ogre::SceneManager** sceneManagerPtr;
	Ogre::SceneNode* node;
	Ogre::SceneNode* root;
public:
	Sprite();
	virtual void move(Ogre::Vector3 moveVector);
	virtual void update(Ogre::Real deltaTime) =0;
	virtual bool checkCollsion(Sprite* other);
	virtual Ogre::AxisAlignedBox getBoundingBox();
	virtual void die() =0;
};
#endif