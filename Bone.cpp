#include "Bone.h"


CBone::CBone(void):isRoot(0)
{

}


CBone::~CBone(void)
{
}


void CBone::setAsRoot(void)
{
	isRoot=1;
}


bool CBone::getIsRoot(void)
{
	return isRoot;
}


void CBone::draw(void)
{

}
