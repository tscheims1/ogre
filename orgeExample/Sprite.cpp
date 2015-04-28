#include "Sprite.h"

Sprite::Sprite(){}

bool Sprite::checkCollsion(Sprite* other)
{
	Ogre::AxisAlignedBox box = mNode->_getWorldAABB();
	return box.intersects(other->getBoundingBox());
}
Ogre::AxisAlignedBox Sprite::getBoundingBox()
{
	return mNode->_getWorldAABB();
}
void Sprite::move(Ogre::Vector3 moveVector)
{
	mNode->translate(moveVector,Ogre::Node::TS_LOCAL);
}