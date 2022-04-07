#include "../../include/Map/Tile.h"

#include <iostream>

Tile::Tile(int x, int y, bool beCrossed) : m_position(x, y), m_beCrossed(beCrossed) {}

Tile::~Tile()
{

}

void Tile::setBeCrossed(bool beCrossed)
{
	m_beCrossed = beCrossed;
}

Position Tile::getPosition() const
{
	return m_position;
}

bool Tile::getBeCrossed() const
{
	return m_beCrossed;
}

void Tile::show() const
{
	std::cout << "   ";
}