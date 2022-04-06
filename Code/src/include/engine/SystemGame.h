/**
 * \file SystemGame.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe SystemGame
 * \version 0.1
 * \date 2022-04-06
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __SYSTEMGAME__
#define __SYSTEMGAME__

#include "../Persos/Bomberman.h"
#include "../Map/Map.h"

/**
 * \class SystemGame
 * \brief Classe permettant de gérer une partie
 * 
 * C'est depuis cette classe que l'on gère une partie de Bomberman, en gérant le tour du joueur, des ennemies, des items et des bombes.
 */
class SystemGame
{
	private:
		Map m_map; /*!< La map de la partie*/
		bool m_endGame;/*!< Permet de savoir si une partie est finit ou non*/

		/**
		 * \brief Gère le tour du joueur
		 * 
		 * Demande au joueur de réaliser une action et réalise cette action si cela est possible
		 * 
		 * \author Hocine HADID
		 */
		void turnPlayer();
		/**
		 * \brief Gère le tour des items
		 * \see Map
		 * 
		 * Fais jouer chaque item en faisant appel à la méthode playItem de la classe Map
		 * 
		 * \author Hocine HADID
		 */
		void turnItems();
		/**
		 * \brief Gère le tour des ennemies
		 * \see Map
		 * 
		 * Fais jouer chaque ennemie en faisant appel à la méthode playEnnemy de la classe Map
		 * 
		 * \author Hocine HADID
		 */
		void turnEnnemy();
		/**
		 * \brief Gère le tour des bombes
		 * \see Map
		 * 
		 * Fais jouer chaque bombe en faisant appel ç la méthode playuBomb de la classe Map
		 * 
		 * \author Hocine HADID
		 */
		void turnBombs();
		
	public:
		/**
		 * \brief Constructeur de la classe SystemGame
		 * 
		 * @param level La map à charger
		 */
		SystemGame(int level = 1);

		/**
		 * \brief Affiche la map et les informations du joueur
		 * \see Map
		 * 
		 * Permet d'afficher la Map avec les informations du joueur : les points de vie et le nombre de bombes restantes.
		 * Fais appel à la méthode showMap de la classe Map
		 * 
		 * \author Hocine HADID
		 */
		void showMap();
		/**
		 * \brief Joue un tour de jeu
		 * 
		 * Permet de jouer un tour en faisant jouer le joueur puis les items, les ennemies et enfin les bombes pour au final afficher la Map.
		 * A la fin du tour vérifie si le joueur a gagné ou perdu.
		 * 
		 * \author Hocine HADID
		 */
		void playTurn();
		/**
		 * \brief accesseur de l'attribut endGame
		 * 
		 * \return vrai si la partie est terminé, faux sinon
		 */
		bool getEndGame();
};

#endif