#include "../../include/Map/Map.h"
#include "../../include/Map/MoveException.h"

#include "../../include/Persos/Ghost.h"
#include "../../include/Persos/Monster.h"
#include "../../include/Persos/Bowman.h"

#include "../../include/Items/Bomb.h"
#include "../../include/Items/MoreLife.h"
#include "../../include/Items/PowerUp.h"
#include "../../include/Items/MoreBomb.h"
#include "../../include/Items/SpeedUp.h"
#include "../../include/Items/ScaleUp.h"

#include <iostream>
#include <fstream>

Map::Map(int level)
{
	loadMap(level);
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

	for (int i = 0; i < m_listBombs.size(); i++)
	{
		delete m_listBombs[i];
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

Bomberman Map::getPlayer() const
{
	return m_player;
}

std::vector <Ennemy*> Map::getListEnnemy() const
{
	return m_listEnnemy;
}

std::vector <Item*> Map::getListItems() const
{
	return m_listItems;
}

std::vector <Bomb*> Map::getListBombs() const
{
	return m_listBombs;
}

void Map::playBomb()
{
	m_listBombs.push_back(new Bomb(m_player.getPosition().getX(), m_player.getPosition().getY()));
	m_player.dropBomb();
}

void Map::loadMap(int map)
{
	std::fstream fileMap;
	std::string line;
	std::string tile;
	int lineMap = 0, columnMap = 0, i;

	std::cout << "===================== LANCEMENT CHARGEMENT MAP ===========================" << std::endl << std::endl;

	if(!m_mapTile.empty())
	{
		for(int i=0; i<m_nbLine; i++)
		{
			for(int j=0; j<m_nbColumn; j++)
			{
				delete m_mapTile[i][j];
			}
			m_mapTile[i].clear();
		}
		m_mapTile.clear();
	}

	if(!m_bombExplosion.empty())
	{
		for (int i = 0; i < m_bombExplosion.size(); i++)
		{
			m_bombExplosion[i].clear();
		}
		m_bombExplosion.clear();
	}
		
	fileMap.open("resources/map/" + std::to_string(map) + ".txt", std::fstream::in);
	
	if(fileMap.is_open())
	{
		fileMap >> m_nbLine;
		fileMap >> m_nbColumn;
		for(int i=0; i<m_nbLine; i++)
		{
			m_mapTile.push_back(std::vector <Tile*>(m_nbColumn));
			m_bombExplosion.push_back(std::vector<utilities::EBombExplosionDirection>(m_nbColumn, utilities::EBombExplosionDirection::NOEXPLOSION));
		}
		
		getline(fileMap, line);
		while(getline(fileMap, line))
		{
			columnMap = 0;
			i=0;
			while(i<line.length())
			{
				if(line[i] != ',')
				{
					tile = "";
					while(line[i] != ',' && i<line.length())
					{
						tile += line[i];
						i++;
					}
					if(tile.compare("P") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Tile(lineMap, columnMap, false);
						m_player = Bomberman(lineMap, columnMap, 5, 1, 5, 5);
					}
					else if(tile.compare("w") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Wall(lineMap, columnMap, false, true, 1);
					}
					else if(tile.compare("W") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Wall(lineMap, columnMap, false, true);
					}
					else if(tile.compare("I") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Wall(lineMap, columnMap, false, false, 0);
					}
					else if(tile.compare("M") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Tile(lineMap, columnMap, false);
						m_listEnnemy.push_back(new Monster(lineMap, columnMap, 2, 1, 1, 0));
					}
					else if(tile.compare("G") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Tile(lineMap, columnMap, true);
						m_listEnnemy.push_back(new Ghost(lineMap, columnMap, 2, 1, 1, 0));
					}
					else if(tile.compare("B") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Tile(lineMap, columnMap, false);
						m_listEnnemy.push_back(new Bowman(lineMap, columnMap, 2, 1, 1, 0));
					}
					else if(tile.compare("ML") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Tile(lineMap, columnMap, true);
						m_listItems.push_back(new MoreLife(lineMap, columnMap, 1));
					}
					else if(tile.compare("PU") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Tile(lineMap, columnMap, true);
						m_listItems.push_back(new PowerUp(lineMap, columnMap, 1));
					}
					else if(tile.compare("MB") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Tile(lineMap, columnMap, true);
						m_listItems.push_back(new MoreBomb(lineMap, columnMap, 3));
					}
					else if(tile.compare("SP") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Tile(lineMap, columnMap, true);
						m_listItems.push_back(new SpeedUp(lineMap, columnMap, 1));
					}
					else if(tile.compare("SC") == 0)
					{
						m_mapTile[lineMap][columnMap] = new Tile(lineMap, columnMap, true);
						m_listItems.push_back(new ScaleUp(lineMap, columnMap, 0.5));
					}
					else if(tile.compare("X") == 0)
					{
						m_target = Tile(lineMap, columnMap, true);
						m_mapTile[lineMap][columnMap] = new Tile(lineMap, columnMap, true);
					}
					else
					{
						m_mapTile[lineMap][columnMap] = new Tile(lineMap, columnMap, true);
					}
					columnMap++;
				}
				i++;
			}
			lineMap++;
		}
		std::cout << "===================== CHARGEMENT MAP TERMINE =============================" << std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl << "### Impossible de charger la map ! Vérifiez que la map existe bien ###" << std::endl << std::endl;
	}
	fileMap.close();
}

bool Map::movePlayer(utilities::EDirection direction, int nbCase)
{
	Bomberman bTest = m_player;
	bTest.move(direction, nbCase);

	if(bTest.getPosition().getX() >= m_nbLine || bTest.getPosition().getY() >= m_nbColumn || bTest.getPosition().getX() < 0 || bTest.getPosition().getY() < 0){
		throw MoveException("\nDéplacement impossible !\nCause : sortie de map");
	}

	if(!m_mapTile[bTest.getPosition().getX()][bTest.getPosition().getY()]->getBeCrossed())
	{
		throw MoveException("\nDéplacement impossible !\nCause : La case ne peut être traversé");
	}

	bTest = m_player;
	if(m_player.move(direction, nbCase))
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

void Map::playEnnemy(int ennemy)
{
	if(ennemy < m_listEnnemy.size() && ennemy >= 0)
	{
		Position lastPosition = m_listEnnemy[ennemy]->getPosition();
		if(m_listEnnemy[ennemy]->play(m_mapTile, &m_player, &m_listItems) != utilities::EDirection::NONE)
		{
			m_mapTile[lastPosition.getX()][lastPosition.getY()]->setBeCrossed(true);
			m_mapTile[m_listEnnemy[ennemy]->getPosition().getX()][m_listEnnemy[ennemy]->getPosition().getY()]->setBeCrossed(false);
		}
	}
}

void Map::playItem(int item)
{
	if(item < m_listItems.size() && item >= 0)
	{
		if(m_listItems[item]->play(m_mapTile, &m_player, &m_listItems))
		{
			m_listItems.erase(m_listItems.begin()+item);
		}
	}
}

void Map::playBomb(int bomb)
{
	if(bomb < m_listBombs.size() && bomb >= 0)
	{
		if(m_listBombs[bomb]->play(m_mapTile, &m_player, &m_listItems))
		{
			bombExplosion(m_listBombs[bomb]->getPosition());
			m_listBombs.erase(m_listBombs.begin()+bomb);
		}
	}
}

void Map::bombExplosion(Position positionExplosion)
{
	for (int line = 0; line < m_nbLine; line++)
	{
		for (int column = 0; column < m_nbColumn; column++)
		{
			if(positionExplosion.getX() == line && positionExplosion.getY() == column)
			{
				m_bombExplosion[line][column] = utilities::EBombExplosionDirection::CENTER;
			}
			else if(positionExplosion.getX()+Bomb::scope > line && line > positionExplosion.getX()-Bomb::scope && positionExplosion.getY() == column)
			{
				m_bombExplosion[line][column] = utilities::EBombExplosionDirection::COLUMN;
			}
			else if(positionExplosion.getY()+Bomb::scope > column && column > positionExplosion.getY()-Bomb::scope && positionExplosion.getX() == line)
			{
				m_bombExplosion[line][column] = utilities::EBombExplosionDirection::LINE;
			}
			else
			{
				m_bombExplosion[line][column] = utilities::EBombExplosionDirection::NOEXPLOSION;
			}

			if(m_bombExplosion[line][column] != utilities::EBombExplosionDirection::NOEXPLOSION)
			{
				bool ok = false;
				int i = 0;
				while(!ok && i < m_listEnnemy.size())
				{
					if(m_listEnnemy[i]->getPosition().getX() == line && m_listEnnemy[i]->getPosition().getY() == column)
					{
						m_listEnnemy[i]->receiveDamage(Bomb::power);
						if(m_listEnnemy[i]->getLife() == 0)
						{
							m_mapTile[line][column]->setBeCrossed(true);
							m_listEnnemy.erase(m_listEnnemy.begin()+i);
						}
						ok = true;
					}
					i++;
				}

				if(!ok && !m_mapTile[line][column]->getBeCrossed())
				{
					if(m_player.getPosition().getX() == line && m_player.getPosition().getY() == column)
					{
						m_player.receiveDamage(Bomb::power);
					}
					else
					{
						Wall *w = reinterpret_cast<Wall*>(m_mapTile[line][column]);
						w->weaken();
						if(w->getNbNecessaryBomb() == 0)
						{
							delete m_mapTile[line][column];
							m_mapTile[line][column] = new Tile(line, column, true);
						}
					}
				}
				
			}
		}
	}
	
}

void Map::eraseBombExplosion()
{
	for (int i = 0; i < m_bombExplosion.size(); i++)
	{
		for (int j = 0; j < m_bombExplosion[i].size(); j++)
		{
			m_bombExplosion[i][j] = utilities::EBombExplosionDirection::NOEXPLOSION;
		}
		
	}
}

void Map::showMap() const
{
	for(int line=0; line<m_nbLine; line++)
	{
		for(int column=0; column<m_nbColumn; column++)
		{
			std::cout << "+---";
		}
		std::cout << "+" << std::endl;

		for(int i=0; i<3; i++)
		{
			for(int column=0; column<m_nbColumn; column++)
			{
				switch (i)
				{
					case 0:
					{
						bool show = false;
						std::cout << "|";
						if(m_bombExplosion[line][column] == utilities::EBombExplosionDirection::COLUMN || m_bombExplosion[line][column] == utilities::EBombExplosionDirection::CENTER)
						{
							std::cout << " | ";
							show = true;
						}
						else if(!m_listItems.empty())
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
							std::cout << "   ";
						}
						
						break;
					}

					case 1:
					{
						bool show = false;
						std::cout << "|";
						//Affichage de la valeur centrale
						if(m_bombExplosion[line][column] == utilities::EBombExplosionDirection::LINE)
						{
							std::cout << "---";
							show = true;
						}
						else if(m_bombExplosion[line][column] == utilities::EBombExplosionDirection::COLUMN)
						{
							std::cout << " | ";
							show = true;
						}
						else if(m_bombExplosion[line][column] == utilities::EBombExplosionDirection::CENTER)
						{
							std::cout << "-@-";
							show = true;
						}

						if(!show && m_player.getPosition() == m_mapTile[line][column]->getPosition())
						{
							m_player.show();
							show = true;
						}

						if(!show && m_target.getPosition() == m_mapTile[line][column]->getPosition())
						{
							std::cout << " X ";
							show = true;
						}
						
						if(!show && !m_listEnnemy.empty())
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

						if(!show && !m_listItems.empty())
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

						if(!show && !m_listBombs.empty())
						{
							int k=0;
							while(k<m_listBombs.size() && m_listBombs[k]->getPosition() != m_mapTile[line][column]->getPosition())
							{
								k++;
							}
							if(k<m_listBombs.size())
							{
								m_listBombs[k]->showMiddle();
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
						std::cout << "|";
						if(m_bombExplosion[line][column] == utilities::EBombExplosionDirection::COLUMN || m_bombExplosion[line][column] == utilities::EBombExplosionDirection::CENTER)
						{
							std::cout << " | ";
							show = true;
						}

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
							std::cout << "   ";
						}
						break;
					}
					
					default:
						std::cout << "|   ";
						break;
				}
			}
			std::cout << "|" << std::endl;
		}
	}
	
	for(int column=0; column<m_nbColumn; column++)
	{
		std::cout << "+---";
	}
	std::cout << "+" << std::endl;
}