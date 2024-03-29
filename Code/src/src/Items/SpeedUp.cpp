#include "../../include/Items/SpeedUp.h"

#include <iostream>

SpeedUp::SpeedUp(int x, int y, int speed): Item(x, y), m_speed(speed)
{

}

SpeedUp::~SpeedUp()
{
	
}

void SpeedUp::increaseSpeed(Bomberman* b)
{
	b->addSpeed(m_speed);
}

void SpeedUp::showTop() const
{
	std::cout << "   ";
}

void SpeedUp::showMiddle() const
{
	std::cout << " SP";
}

void SpeedUp::showBottom() const
{
	std::cout << "   ";
}

bool SpeedUp::play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items)
{
	bool remove = false;

	if(player->getPosition() == m_position)
	{
		increaseSpeed(player);
		remove = true;
	}

	return remove;
}