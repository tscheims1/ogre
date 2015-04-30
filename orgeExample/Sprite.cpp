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

	mNode->setPosition(moveVector+mNode->getPosition());
	std::string s = "posFighter: "+Ogre::StringConverter::toString(mNode->getPosition()) + "\n";
	OutputDebugStringA (s.c_str());
}