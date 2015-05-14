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
	mCurrentMoveVector = moveVector;
	mNode->setPosition(moveVector+mNode->getPosition());
	std::string s = "posFighter: "+Ogre::StringConverter::toString(moveVector) + "\n";
	//OutputDebugStringA (s.c_str());
}
bool Sprite::checkBeforeCollide(Sprite* other,int distance)
{
	Ogre::Vector3 absVector = mNode->getPosition();
	Ogre::Ray ray(absVector,mCurrentMoveVector);
	Ogre::AxisAlignedBox  box = other->getBoundingBox();
	std::pair<bool,float> result = ray.intersects(box);

	if(result.first == false)
		return false;

	//OutputDebugStringA(std::to_string(result.second).c_str());

	if(result.second < distance)
		return true;
}