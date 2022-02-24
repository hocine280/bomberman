#include "../../include/Map/Position.h"

int Position::getX() const
{
	return m_x;
}

int Position::getY() const
{
	return m_y;
}

void Position::setX(int x)
{
	if(x >= 0)
	{
		this->m_x = x;
	}
}

void Position::setY(int y)
{
	if(y >= 0)
	{
		this->m_y = y;
	}
}