#include "../../include/Map/Map.h"

Map::Map() {}

Map::~Map()
{

}

int Map::getNbColumn() const
{
	return m_nbColumn;
}

int Map::getNbLine() const
{
	return m_nbLine;
}

Tile Map::getTarget() const
{
	return m_target;
}

Bomberman Map::getPlayer() const
{
	return m_player;
}

void Map::showMap() const
{

}