#include "../../include/Items/Item.h"

Item::Item(Position position): m_position(position){}

Item::~Item()
{
	
}

Position Item::getPosition() const
{
	return m_position;
}

void Item::show() const
{

}