#include "../../include/Map/Tile.h"

#include <iostream>

Tile::Tile(int x, int y, bool beCrossed) : m_position(x, y), m_beCrossed(beCrossed) {}

Tile::~Tile()
{

}

Position Tile::getPosition() const
{
	return m_position;
}

void Tile::show() const
{
	std::cout << " ";
}

bool Tile::getBeCrossed() const
{
	return m_beCrossed;
}