#include "../../include/Items/MoreLife.h"

#include <iostream>

MoreLife::MoreLife(int x, int y, int lifePoint): Item(x, y), m_lifePoint(lifePoint)
{

}

MoreLife::~MoreLife()
{
	
}

void MoreLife::increaseLife(Bomberman* b)
{
	b->addLife(m_lifePoint);
}

void MoreLife::showTop() const
{
	std::cout << "   ";
}

void MoreLife::showMiddle() const
{
	std::cout << " ML";
}

void MoreLife::showBottom() const
{
	std::cout << "   ";
}