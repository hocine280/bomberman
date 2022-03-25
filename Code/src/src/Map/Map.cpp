#include "../../include/Map/Map.h"
#include "../../include/Persos/Ghost.h"
#include "../../include/Map/Position.h"
#include "../../include/Map/MoveException.h"

#include <iostream>

using namespace std;

Map::Map(Bomberman& player, int nbLine, int nbColumn): m_player(player), m_nbLine(nbLine), m_nbColumn(nbColumn)
{
	for(int i=0; i<m_nbLine; i++)
	{
		m_mapTile.push_back(vector <Tile*>(m_nbColumn));
		for(int j=0; j<m_nbColumn; j++)
		{
			if(i == 2 && j == 0)
			{
				m_mapTile[i][j] = new Wall(i, j, false, true, 2);
			}
			else
			{
				m_mapTile[i][j] = new Tile(i, j, true);
			}
			
		}
	}
	m_listEnnemy.push_back(new Ghost(0, 1, 1, 1, 2));
	m_target = Tile(0, 0, false);
}

Map::~Map()
{
	for(int i=0; i<m_nbLine; i++)
	{
		for(int j=0; j<m_nbColumn; j++)
		{
			delete m_mapTile[i][j];
		}
	}

	for(int i=0; i<m_listEnnemy.size(); i++)
	{
		delete m_listEnnemy[i];
	}

	for(int i=0; i<m_listItems.size(); i++)
	{
		delete m_listItems[i];
	}
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

bool Map::movePlayer(utilities::EDirection direction)
{
	Bomberman bTest = m_player;
	bTest.move(direction);

	if(bTest.getPosition().getX() >= m_nbLine || bTest.getPosition().getY() >= m_nbColumn || bTest.getPosition().getX() < 0 || bTest.getPosition().getY() < 0){
		throw MoveException("\nDéplacement impossible !\nCause : sortie de map");
	}

	if(!m_mapTile[bTest.getPosition().getX()][bTest.getPosition().getY()]->getBeCrossed())
	{
		throw MoveException("\nDéplacement impossible !\nCause : La case ne peut être traversé");
	}

	bTest = m_player;
	if(m_player.move(direction))
	{
		m_mapTile[bTest.getPosition().getX()][bTest.getPosition().getY()]->setBeCrossed(true);
		m_mapTile[m_player.getPosition().getX()][m_player.getPosition().getY()]->setBeCrossed(false);
		return true;
	}
	else
	{
		throw MoveException("Une erreur est survenue ! Le déplacement n'a pas pu être effectué");
	}
}

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
					{
						bool show = false;
						if(!m_listItems.empty())
						{
							int k=0;
							while(k<m_listItems.size() && m_listItems[k]->getPosition() != m_mapTile[line][column]->getPosition())
							{
								k++;
							}
							if(k<m_listItems.size())
							{
								m_listItems[k]->showTop();
								show = true;
							}
						}
						if(!show)
						{
							cout << "|   ";
						}
						
						break;
					}

					case 1:
					{
						bool show = false;
						cout << "|";
						
						//Affichage de la valeur centrale
						if(m_player.getPosition() == m_mapTile[line][column]->getPosition())
						{
							m_player.show();
							show = true;
						}
						
						if(!m_listEnnemy.empty() && !show)
						{
							int k=0;
							while(k<m_listEnnemy.size() && m_listEnnemy[k]->getPosition() != m_mapTile[line][column]->getPosition())
							{
								k++;
							}
							if(k<m_listEnnemy.size())
							{
								m_listEnnemy[k]->show();
								show = true;
							}
						}

						if(!m_listItems.empty() && !show)
						{
							int k=0;
							while(k<m_listItems.size() && m_listItems[k]->getPosition() != m_mapTile[line][column]->getPosition())
							{
								k++;
							}
							if(k<m_listItems.size())
							{
								m_listItems[k]->showMiddle();
								show = true;
							}
						}
						
						if(!show)
						{
							m_mapTile[line][column]->show();
						}
						
						break;
					}

					case 2:
					{
						bool show = false;
						if(!m_listItems.empty())
						{
							int k=0;
							while(k<m_listItems.size() && m_listItems[k]->getPosition() != m_mapTile[line][column]->getPosition())
							{
								k++;
							}
							if(k<m_listItems.size())
							{
								m_listItems[k]->showBottom();
								show = true;
							}
						}
						if(!show)
						{
							cout << "|   ";
						}
						break;
					}
					
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