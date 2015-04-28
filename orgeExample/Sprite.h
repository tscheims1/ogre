#ifndef __SPRITE_H__
#define __SPRITE_H__
class Sprite
{
protected:
	Ogre::Entity* mEntity;
	Ogre::SceneManager** mSceneManagerPtr;
	Ogre::SceneNode* mNode;
	Ogre::SceneNode* mRoot;
public:
	Sprite();
	virtual void move(Ogre::Vector3 moveVector);
	virtual void update(Ogre::Real deltaTime) =0;
	virtual bool checkCollsion(Sprite* other);
	virtual Ogre::AxisAlignedBox getBoundingBox();
	virtual void die() =0;
};
#endif