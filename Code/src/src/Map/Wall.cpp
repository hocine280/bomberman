#include "../../include/Map/Wall.h"

#include <iostream>

Wall::Wall(int x, int y, bool beCrossed, bool destructible, int nbNecessaryBomb): Tile(x, y, beCrossed), m_destructible(destructible), m_nbNecessaryBomb(nbNecessaryBomb)
{
	if(x < 0 || x > 7)
	{
		x = 0;
	}

	if(y < 0 || y > 7)
	{
		y = 0;
	}

	if(nbNecessaryBomb < 0)
	{
		nbNecessaryBomb = 0;
		destructible = false;
	}
}

Wall::~Wall()
{

}

bool Wall::getDestructible() const
{
	return m_destructible;
}

int Wall::getNbNecessaryBomb() const
{
	return m_nbNecessaryBomb;
}

void Wall::show() const
{
	std::cout << "W";
}

void Wall::weaken()
{
	if(m_destructible == true && m_nbNecessaryBomb > 0)
	{
		m_nbNecessaryBomb--;
	}
}