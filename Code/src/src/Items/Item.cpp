#include "../../include/Items/Item.h"

Item::Item(int x, int y, int powerPoint): m_position(x, y) {}

Item::~Item()
{
	
}

Position Item::getPosition() const
{
	return m_position;
}