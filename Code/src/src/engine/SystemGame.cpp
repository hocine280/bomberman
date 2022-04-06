#include "../../include/engine/SystemGame.h"
#include "../../include/engine/utilities.h"

#include "../../include/Map/MoveException.h"

#include "../../include/Persos/Ennemy.h"

#include <iostream>
#include <limits>

SystemGame::SystemGame(int level): m_map(level), m_endGame(false)
{

}

void SystemGame::showMap()
{
	std::cout << "Point de vie restant : " << m_map.getPlayer().getLife() << "	Nombre de bombes restantes : " << m_map.getPlayer().getNbBomb() << std::endl << std::endl;

	m_map.showMap();
	m_map.eraseBombExplosion();
}

bool SystemGame::getEndGame()
{
	return m_endGame;
}

void SystemGame::playTurn()
{
	turnPlayer();
	turnItems();
	turnEnnemy();
	turnBombs();

	showMap();

	if(m_map.getPlayer().getLife() == 0)
	{
		m_endGame = true;
		std::cout << std::endl << "Perdu ! Vous n'avez plus de vie ..." << std::endl;
	}
	else if(m_map.getPlayer().getPosition() == m_map.getTarget().getPosition() && m_map.getListEnnemy().empty())
	{
		m_endGame = true;
		std::cout << std::endl << "Victoire ! Vous avez atteint l'objectif et éliminé tous les ennemies !!" << std::endl;
	}
}

void SystemGame::turnPlayer()
{
	int action;
	bool finAction = false;
	do
	{	
		std::cout << std::endl << std::endl;
		std::cout << "=============== Action joueur =================" << std::endl;
		std::cout << std::endl;
		std::cout << "      ------- Déplacement --------" << std::endl;
		std::cout << "8 - Déplacement vers le haut" << std::endl;
		std::cout << "4 - Déplacement vers la gauche" << std::endl;
		std::cout << "6 - Déplacement vers la droite" << std::endl;
		std::cout << "2 - Déplacement vers le bas" << std::endl;
		std::cout << std::endl;
		std::cout << "      ---------- Action ----------" << std::endl;
		std::cout << "5 - Poser une bombe" << std::endl;
		std::cout << "1 - Quitter la partie" << std::endl;
		std::cout << std::endl;
		std::cout << "Saisir votre choix : ";

		std::cin >> action;
		switch (action)
		{
			case 8:
				try
				{
					int nbCase = 1;
					if(m_map.getPlayer().getSpeed() > 1)
					{
						std::cout << "De combien de case souhaitez-vous vous déplacer ?" << std::endl;
						for (int i = 0; i < m_map.getPlayer().getSpeed(); i++)
						{
							std::cout << (i+1) << " - " << (i+1) << " case(s)" << std::endl;
						}
						do
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cin >> nbCase;
						} while (nbCase < 1 && nbCase > m_map.getPlayer().getSpeed());
					}
					m_map.movePlayer(utilities::EDirection::TOP, nbCase);
					finAction = true;
				}
				catch(const MoveException& e)
				{
					std::cerr << e.what() << '\n';
				}
				
				break;
				
			case 4:
				try
				{
					int nbCase = 1;
					if(m_map.getPlayer().getSpeed() > 1)
					{
						std::cout << "De combien de case souhaitez-vous vous déplacer ?" << std::endl;
						for (int i = 0; i < m_map.getPlayer().getSpeed(); i++)
						{
							std::cout << (i+1) << " - " << (i+1) << " case(s)" << std::endl;
						}
						do
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cin >> nbCase;
						} while (nbCase < 1 && nbCase > m_map.getPlayer().getSpeed());
					}
					m_map.movePlayer(utilities::EDirection::LEFT, nbCase);
					finAction = true;
				}
				catch(const MoveException& e)
				{
					std::cerr << e.what() << '\n';
				}
				break;

			case 6:
				try
				{
					int nbCase = 1;
					if(m_map.getPlayer().getSpeed() > 1)
					{
						std::cout << "De combien de case souhaitez-vous vous déplacer ?" << std::endl;
						for (int i = 0; i < m_map.getPlayer().getSpeed(); i++)
						{
							std::cout << (i+1) << " - " << (i+1) << " case(s)" << std::endl;
						}
						do
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cin >> nbCase;
						} while (nbCase < 1 && nbCase > m_map.getPlayer().getSpeed());
					}
					m_map.movePlayer(utilities::EDirection::RIGHT, nbCase);
					finAction = true;
				}
				catch(const MoveException& e)
				{
					std::cerr << e.what() << '\n';
				}
				break;

			case 2:
				try
				{
					int nbCase = 1;
					if(m_map.getPlayer().getSpeed() > 1)
					{
						std::cout << "De combien de case souhaitez-vous vous déplacer ?" << std::endl;
						for (int i = 0; i < m_map.getPlayer().getSpeed(); i++)
						{
							std::cout << (i+1) << " - " << (i+1) << " case(s)" << std::endl;
						}
						do
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cin >> nbCase;
						} while (nbCase < 1 && nbCase > m_map.getPlayer().getSpeed());
					}
					m_map.movePlayer(utilities::EDirection::BOTTOM, nbCase);
					finAction = true;
				}
				catch(const MoveException& e)
				{
					std::cerr << e.what() << '\n';
				}
				break;

			case 5:
				if(m_map.getPlayer().getNbBomb() > 0)
				{
					m_map.playBomb();
					finAction = true;
				}
				else
				{
					std::cout << "Vous n'avez plus de bombes ..." << std::endl;
				}
				break;

			case 1:
				m_endGame = true;
				finAction = true;
				break;
			
			default:
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				finAction = false;
				break;
		}
	} while (!finAction);
}

void SystemGame::turnItems()
{
	for (int i = 0; i < m_map.getListItems().size(); i++)
	{
		m_map.playItem(i);
	}
	
}

void SystemGame::turnEnnemy()
{
	for (int i = 0; i < m_map.getListEnnemy().size(); i++)
	{
		m_map.playEnnemy(i);
	}
}

void SystemGame::turnBombs()
{
	for (int i = 0; i < m_map.getListBombs().size(); i++)
	{
		m_map.playBomb(i);
	}
	
}