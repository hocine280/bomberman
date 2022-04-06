/**
 * \file MoreBomb.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe MoreBomb
 * \version 0.1
 * \date 2022-04-06
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __MOREBOMB__
#define __MOREBOMB__

#include "Item.h"
#include "../Persos/Bomberman.h"

/**
 * \class MoreBomb
 * \brief La classe MoreBomb hérite de la classe Item et permets de gérer les items de type MoreBomb
 * \see Item
 * 
 * Permets de gérer les items de type MoreBomb qui permettent d'ajouter des bombes au Bomberman
 * 
 * \author Hocine HADID
 */
class MoreBomb: public Item
{
	private:
		int m_nbBomb; /*!< Le nombre de bombe*/
		
	public:
		/**
		 * \brief Constructeur d'un item MoreBomb
		 * 
		 * \param x La ligne sur laquelle se situe la MoreBomb
		 * \param y La colonne sur laquelle se situe la MoreBomb
		 * \param nbBomb Le nombre de bombe que rajoutera l'item
		 */
		MoreBomb(int x = 0, int y = 0, int nbBomb = 1);
		/**
		 * \brief Destructeur de la MoreBomb
		 * 
		 */
		~MoreBomb();

		/**
		 * \brief Rajoute le nombre de Bombe au Bomberman
		 * \see Bomberman
		 * 
		 * @param b Le bomberman auquelle il faut rajouter le nombre de bombe
		 * 
		 * \author Hocine HADID
		 */
		void increaseNbBomb(Bomberman* b);

		/**
		 * \brief Affiche la partie haute de la case lors de l'affichage de la MoreBomb
		 * 
		 * \author Hocine HADID
		 */
		void showTop() const override;
		/**
		 * \brief Affiche la partie du milieu de la case lors de l'affichage de la MoreBomb
		 * 
		 * \author Hocine HADID
		 */
		void showMiddle() const override;
		/**
		 * \brief Affiche la partie basse de la case lors de l'affichage de la MoreBomb
		 * 
		 * \author Hocine HADID
		 */
		void showBottom() const override;

		/**
		 * \brief Permet de jouer la MoreBomb
		 * \see Bomberman
		 * \see Item
		 * \see Tile
		 * 
		 * Joue la MoreBomb, si la MoreBomb est sur la même case que le joueur alors rajoute le nombre de bomb indiqué au joueur.
		 * 
		 * \param map La map sur laquelle la MoreBomb est joué
		 * \param player Le joueur présent sur la map
		 * \param items La liste des items présents sur la map
		 * \return true si la MoreBomb doit être supprimé, false sinon
		 * 
		 * \author Hocine HADID
		 */
		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
};

#endif