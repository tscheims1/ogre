#ifndef __SPRITE_H__
#define __SPRITE_H__
class Sprite
{
protected:
	Ogre::Entity* entity;
	Ogre::SceneNode* node;
public:
	Sprite();
	virtual void move(Ogre::Vector3 moveVector);
	virtual bool checkCollsion(Sprite* other);
	virtual Ogre::AxisAlignedBox getBoundingBox();
};
#endif