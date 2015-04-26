#include "Sprite.h"

Sprite::Sprite(){}

bool Sprite::checkCollsion(Sprite* other)
{
	Ogre::AxisAlignedBox box = node->_getWorldAABB();
	return box.intersects(other->getBoundingBox());
}
Ogre::AxisAlignedBox Sprite::getBoundingBox()
{
	return node->_getWorldAABB();
}
void Sprite::move(Ogre::Vector3 moveVector)
{
	node->translate(moveVector,Ogre::Node::TS_LOCAL);
}