#include "../../include/Items/PowerUp.h"

#include "../../include./Items/Bomb.h"

PowerUp::PowerUp(int x, int y, int powerPoint): Item(x, y), m_powerPoint(powerPoint)
{

}

void PowerUp::increasePower()
{
	Bomb::power += m_powerPoint;
}

void PowerUp::showTop() const
{
	std::cout << "   ";
}

void PowerUp::showMiddle() const
{
	std::cout << " PU";
}

void PowerUp::showBottom() const
{
	std::cout << "   ";
}