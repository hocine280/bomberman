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
	m_map.showMap();
}

bool SystemGame::endGame()
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
					m_map.movePlayer(utilities::EDirection::TOP);
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
					m_map.movePlayer(utilities::EDirection::LEFT);
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
					m_map.movePlayer(utilities::EDirection::RIGHT);
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
					m_map.movePlayer(utilities::EDirection::BOTTOM);
					finAction = true;
				}
				catch(const MoveException& e)
				{
					std::cerr << e.what() << '\n';
				}
				break;

			case 5:
				m_map.addBomb(m_map.getPlayer().getPosition());
				finAction = true;
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