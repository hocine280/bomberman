#include "../../include/Map/Map.h"

Map::Map(int nbLine, int nbColumn): m_nbLine(nbLine), m_nbColumn(nbColumn)
{
	loadMap();
}

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

void Map::loadMap()
{
	m_mapTile = (Tile**) malloc(nbLine * sizeof(Tile*));
	for(int i=0; i<m_nbLine; i++)
	{
		m_mapTile[i] = (Tile*) malloc(m_nbColumn * sizeof(Tile));
	}

	for(i=0; i<m_nbLine; i++)
	{
		for(int j=0; j<m_nbColumn; j++)
		{
			Tile t();
			m_mapTile[i][j] = &t;
		}
	}
}

void Map::showMap() const
{

}