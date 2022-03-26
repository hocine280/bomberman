#include <iostream>
#include <limits>

#include "src/include/engine/SystemGame.h"

void showHome();
void showMenu();
void playGame(int level);

int main(void)
{
	int choix;

	showHome();
	
	do
	{
		showMenu();
		std::cout << std::endl << "Votre décision : ";
		std::cin >> choix;

		switch (choix)
		{
			case 1:
				std::cout << std::endl << std::endl;
				std::cout << "                                 ###      A BIENTOT SUR BOMBERMAN      ###                                   " << std::endl << std::endl;
				break;

			case 2:
				int level;
				std::cout << std::endl << std::endl;
				std::cout << "=============================================================================================================" << std::endl;
				std::cout << "                                            LANCEMENT D'UNE PARTIE                                           " << std::endl;
				std::cout << "=============================================================================================================" << std::endl;
				do
				{
					std::cout << std::endl << "Sélectionnez la map souhaitée :";
					std::cin >> level;
					if(level != 1)
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "Cette map n'existe pas" << std::endl;
						level = -1;
					}
				} while (level == -1);
				playGame(level);
				break;
			
			default:
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << "Cette action n'est pas possible" << std::endl << std::endl;
				choix = 5;
				break;
		}
	}while(choix != 1);
	
	return 0;
}

void playGame(int level)
{
	std::cout << "LANCEMENT DE LA PARTIE AVEC LA MAP " << level << std::endl;
	SystemGame SG(level);

	while(!SG.endGame())
	{
		SG.showMap();
		SG.playTurn();
	}
}

void showHome()
{
	std::cout << std::endl << std::endl;

	std::cout << "=============================================================================================================" << std::endl << std::endl;

	std::cout << "               ######    #####   ##   ##  ######   #######  ######   ##   ##    ##     ##   ##               " << std::endl;
	std::cout << "                ##  ##  ##   ##  ### ###   ##  ##   ##   #   ##  ##  ### ###   ####    ###  ##               " << std::endl;
	std::cout << "                ##  ##  ##   ##  #######   ##  ##   ## #     ##  ##  #######  ##  ##   #### ##               " << std::endl;
	std::cout << "                #####   ##   ##  #######   #####    ####     #####   #######  ##  ##   ## ####               " << std::endl;
	std::cout << "                ##  ##  ##   ##  ## # ##   ##  ##   ## #     ## ##   ## # ##  ######   ##  ###               " << std::endl;
	std::cout << "                ##  ##  ##   ##  ##   ##   ##  ##   ##   #   ##  ##  ##   ##  ##  ##   ##   ##               " << std::endl;
	std::cout << "               ######    #####   ##   ##  ######   #######  #### ##  ##   ##  ##  ##   ##   ##               " << std::endl;
	
	std::cout << std::endl;
	std::cout << "=============================================================================================================" << std::endl << std::endl;

	std::cout << "                                 ### BIENVENUE SUR THE GREAT BOMBERMAN ###                                   " << std::endl << std::endl;
}

void showMenu()
{
	std::cout << "                                 ###               MENU                ###                                   " << std::endl << std::endl;
	std::cout << "  1 - Quitter" << std::endl;
	std::cout << "  2 - Lancer une game" << std::endl;
	std::cout << "  3 - Afficher les règles du jeux" << std::endl;
}