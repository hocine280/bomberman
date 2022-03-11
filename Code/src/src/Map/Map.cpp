#include "../../include/Map/Map.h"

#include <iostream>

using namespace std;

Map::Map(int nbLine, int nbColumn): m_nbLine(nbLine), m_nbColumn(nbColumn)
{
	for(int i=0; i<m_nbLine; i++)
	{
		m_mapTile.push_back(vector <Tile>(m_nbColumn));
		for(int j=0; j<m_nbColumn; j++)
		{
			Tile t(i, j, true);
			m_mapTile[i][j] = t;
		}
	}
	m_listWall.push_back(Wall(1, 0, false, true, 2));
	m_target = Tile(0, 0, false);
	m_player = Bomberman(1, 1, 3, 1, 5, 2);
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
/*
Bomberman Map::getPlayer() const
{
	return m_player;
}*/

void Map::showMap() const
{
	for(int line=0; line<m_nbLine; line++)
	{
		for(int column=0; column<m_nbColumn; column++)
		{
			cout << "+---";
		}
		cout << "+" << endl;

		for(int i=0; i<3; i++)
		{
			for(int column=0; column<m_nbColumn; column++)
			{
				switch (i)
				{
					case 0:
						cout << "|   ";
						break;

					case 1:
					{
						cout << "| ";
						
						//Affichage de la valeur centrale
						if(m_player.getPosition().getX() == line && m_player.getPosition().getY() == column)
						{
							m_player.show();
						}
						else if(!m_listWall.empty())
						{
							int k = 0;
							while((m_listWall[k].getPosition().getX() != line || m_listWall[k].getPosition().getY() != column) && k<m_listWall.size())
							{
								k++;
							}
							if(k<m_listWall.size())
							{
								m_listWall[k].show();
							}
							else
							{
								
								m_mapTile[line][column].show();
							}
						}
						else
						{
							m_mapTile[line][column].show();
						}
						
						cout << " ";
						break;
					}

					case 2:
						cout << "|   ";
						break;
					
					default:
						cout << "|   ";
						break;
				}
			}
			cout << "|" << endl;
		}
	}
	
	for(int column=0; column<m_nbColumn; column++)
	{
		cout << "+---";
	}
	cout << "+" << endl;
}