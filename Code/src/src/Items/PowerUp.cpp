#include "../../include/Items/PowerUp.h"
#include "../../include/Items/Bomb.h"

#include <iostream>

PowerUp::PowerUp(int x, int y, int powerPoint): Item(x, y), m_powerPoint(powerPoint)
{

}

PowerUp::~PowerUp()
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

bool PowerUp::play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items)
{
	bool remove = false;

	if(player->getPosition() == m_position)
	{
		increasePower();
		remove = true;
	}

	return remove;
}