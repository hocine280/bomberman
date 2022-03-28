#include "../../include/Items/MoreBomb.h"

#include <iostream>

MoreBomb::MoreBomb(int x, int y, int nbBomb): Item(x, y), m_nbBomb(nbBomb)
{

}

MoreBomb::~MoreBomb()
{
	
}

void MoreBomb::increaseNbBomb(Bomberman* b)
{
	b->addBomb(m_nbBomb);
}

void MoreBomb::showTop() const
{
	std::cout << "   ";
}

void MoreBomb::showMiddle() const
{
	std::cout << " MB";
}

void MoreBomb::showBottom() const
{
	std::cout << "   ";
}

bool MoreBomb::play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items)
{
	bool remove = false;
	
	if(player->getPosition() == m_position)
	{
		increaseNbBomb(player);
		remove = true;
	}

	return remove;
}