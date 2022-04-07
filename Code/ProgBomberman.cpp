/**
 * \file ProgBomberman.cpp
 * \author Pierre CHEMIN & Hocine HADID
 * \brief Fichier contenant la classe principal permettant de gérer le jeu du Bomberman
 * \version 0.1
 * \date 2022-04-08
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <limits>
#include <fstream>

#include "src/include/engine/SystemGame.h"

/**
 * \brief Permets d'afficher le message d'accueil
 * 
 */
void showHome();
/**
 * \brief Permets d'afficher le menu du jeu
 * 
 */
void showMenu();
/**
 * \brief Permets de lancer une parie
 * 
 * \param level Le niveau de la Map choisit
 */
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
				std::cout << std::endl << std::endl <<
				"                                 ###      A BIENTOT SUR BOMBERMAN      ###                                   " << std::endl << std::endl;
				break;

			case 2:
				int level;
				std::cout << std::endl << std::endl <<
				"=============================================================================================================" << std::endl <<
				"                                            LANCEMENT D'UNE PARTIE                                           " << std::endl <<
				"=============================================================================================================" << std::endl;
				do
				{
					std::cout << std::endl << "Sélectionnez la map souhaitée :";
					std::cin >> level;
					std::cin.clear();

					std::fstream fileTest;
					fileTest.open("resources/map/" + std::to_string(level) + ".txt");
					if(fileTest.fail())
					{
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "Cette map n'existe pas" << std::endl;
						level = -1;
					}
					fileTest.close();
					
				} while (level == -1);
				playGame(level);
				break;

			case 3:
				std::cout << std::endl << std::endl <<
				"                                 ###             LES REGLES            ###                                   " << std::endl << std::endl <<
				"Le but du jeux est d'atteindre la position marqué par un X. Mais cela ne sera pas sans peine !!" << std::endl <<
				"En effet ! Des hordes d'ennemies vous en empêcheront et pour cela ils vous attaqueront de diverses manières !" << std::endl <<
				"Passons en revue ces ennemies :" << std::endl <<
				"1 - Monster : Ce petit monstre ne vous fera pas grand mal tant que vous vous éloignerez de lui ! En effet, il pourrait vous toucher et pour se laver ce n'est pas évident ..." << std::endl <<
				"2 - Ghost : Celui là est un peu plus coriace étant donné que ce petit fantôme pourra traverser tous les murs, les bombes ainsi que ses copains." << std::endl <<
				"3 - Bowman : Redoutable archer le Bowman vous visera sans scrupule dès que vous serez dans son viseur !! Attention à ne pas vous aligner avec lui ou soyez sûr d'être assez loin et protéger !" << std::endl << std::endl <<
				"Malheureusement éviter les ennemies ne suffira pas ... Car la fuite n'est pas une victoire ! Il va falloir se battre et atteindre la case ne suffira pas !" << std::endl <<
				"Soyez un vrai Bomberman, maître de la destruction et posez vos bombes pour éliminer tous vos adversaires !" << std::endl <<
				"Une fois cela fait rendez-vous au point X pour l'emporter !" << std::endl << std::endl <<
				"Courage petit Bomberman et fais tout péteeeeeeeeeeeeeeeeeeeeeeeeeeer !!!!!" << std::endl << std::endl;
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

	SG.showMap();
	while(!SG.getEndGame())
	{
		SG.playTurn();
	}
}

void showHome()
{
	std::cout << std::endl << std::endl <<

	"=============================================================================================================" << std::endl << std::endl <<

	"               ######    #####   ##   ##  ######   #######  ######   ##   ##    ##     ##   ##               " << std::endl <<
	"                ##  ##  ##   ##  ### ###   ##  ##   ##   #   ##  ##  ### ###   ####    ###  ##               " << std::endl <<
	"                ##  ##  ##   ##  #######   ##  ##   ## #     ##  ##  #######  ##  ##   #### ##               " << std::endl <<
	"                #####   ##   ##  #######   #####    ####     #####   #######  ##  ##   ## ####               " << std::endl <<
	"                ##  ##  ##   ##  ## # ##   ##  ##   ## #     ## ##   ## # ##  ######   ##  ###               " << std::endl <<
	"                ##  ##  ##   ##  ##   ##   ##  ##   ##   #   ##  ##  ##   ##  ##  ##   ##   ##               " << std::endl <<
	"               ######    #####   ##   ##  ######   #######  #### ##  ##   ##  ##  ##   ##   ##               " << std::endl << std::endl <<
	
	"=============================================================================================================" << std::endl << std::endl <<

	"                                 ### BIENVENUE SUR THE GREAT BOMBERMAN ###                                   " << std::endl << std::endl;
}

void showMenu()
{
	std::cout << "                                 ###               MENU                ###                                   " << std::endl << std::endl;
	std::cout << "  1 - Quitter" << std::endl;
	std::cout << "  2 - Lancer une game" << std::endl;
	std::cout << "  3 - Afficher les règles du jeux" << std::endl;
}