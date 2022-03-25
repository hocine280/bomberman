#include "../../include/engine/SystemGame.h"
#include "../../include/engine/utilities.h"

#include <iostream>

SystemGame::SystemGame(): m_player(), m_map(m_player, 4, 5)
{

}

void SystemGame::showMap()
{
	m_map.showMap();
}

void SystemGame::playTurn()
{
	turnPlayer();
	turnBomb();
	turnEnnemy();

	showMap();
}

void SystemGame::turnPlayer()
{
	int action;
	bool finAction = 1;
	do
	{
		std::cout << std::endl << std::endl;
		std::cout << "=============== Action joueur =================" << std::endl;
		std::cout << std::endl;
		std::cout << "      ------- Déplacement --------" << std::endl;
		std::cout << "8 - Déplacement vers le haut" << std::endl;
		std::cout << "4 - Déplacement vers la gauche" << std::endl;
		std::cout << "6 - Déplacement vers la droite" << std::endl;
		std::cout << "2 - Déplacement vers la bas" << std::endl;
		std::cout << std::endl;
		std::cout << "      -------- Action -----------" << std::endl;
		std::cout << "5 - Poser une bombe" << std::endl;
		std::cout << std::endl;
		std::cout << "Saisir votre action : ";

		std::cin >> action;
		switch (action)
		{
			case 8:
				m_map.movePlayer(utilities::EDirection::TOP);
				finAction = 0;
				break;
				
			case 4:
				m_map.movePlayer(utilities::EDirection::LEFT);
				finAction = 0;
				break;

			case 6:
				m_map.movePlayer(utilities::EDirection::RIGHT);
				finAction = 0;
				break;

			case 2:
				m_map.movePlayer(utilities::EDirection::BOTTOM);
				finAction = 0;
				break;

			case 5:
				finAction = 0;
				break;
			
			default:
				finAction = 1;
				break;
		}
	} while (finAction);
}

void SystemGame::turnBomb()
{
	
}

void SystemGame::turnEnnemy()
{

}