#include "../../include/Map/Tile.h"

Tile::Tile(int x, int y, bool beCrossed) : m_position(x, y), m_beCrossed(beCrossed) {}

Tile::~Tile()
{

}

Position Tile::getPosition() const
{
	return m_position;
}

bool Tile::getBeCrossed() const
{
	return m_position;
}