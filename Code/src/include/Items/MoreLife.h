/**
 * \file MoreLife.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe MoreLife
 * \version 0.1
 * \date 2022-04-06
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __MORELIFE__
#define __MORELIFE__

#include "Item.h"
#include "../Persos/Bomberman.h"

/**
 * \class MoreLife
 * \brief La classe MoreLife hérite de la classe Item et permets de gérer les items de type MoreLife
 * \see Item
 * 
 * Permets de gérer les items de type MoreLife qui permettent d'ajouter de la vie au Bomberman
 * 
 * \author Hocine HADID
 */
class MoreLife: public Item
{
	private:
		int m_lifePoint; /*!< Le nombre de point de vie à rajouter*/

	public:
		/**
		 * \brief Constructeur d'un item MoreLife
		 * 
		 * \param x La ligne sur laquelle se situe la MoreLife
		 * \param y La colonne sur laquelle se situe la MoreLife
		 * \param lifePoint Le nombre de point de vie que rajoutera l'item
		 */
		MoreLife(int x = 0, int y = 0, int lifePoint = 1);
		/**
		 * \brief Destructeur de la MoreLife
		 * 
		 */
		~MoreLife();

		/**
		 * \brief Rajoute le nombre de point de vie au Bomberman
		 * \see Bomberman
		 * 
		 * @param b Le bomberman auquelle il faut rajouter le nombre de point de vie
		 * 
		 * \author Hocine HADID
		 */
		void increaseLife(Bomberman* b);

		/**
		 * \brief Affiche la partie haute de la case lors de l'affichage de la MoreLife
		 * 
		 * \author Hocine HADID
		 */
		void showTop() const override;
		/**
		 * \brief Affiche la partie du milieu de la case lors de l'affichage de la MoreLife
		 * 
		 * \author Hocine HADID
		 */
		void showMiddle() const override;
		/**
		 * \brief Affiche la partie basse de la case lors de l'affichage de la MoreLife
		 * 
		 * \author Hocine HADID
		 */
		void showBottom() const override;

		/**
		 * \brief Permet de jouer la MoreLife
		 * \see Bomberman
		 * \see Item
		 * \see Tile
		 * 
		 * Joue la MoreLife, si la MoreLife est sur la même case que le joueur alors rajoute le nombre de point de vie indiqué au joueur.
		 * 
		 * \param map La map sur laquelle la MoreLife est joué
		 * \param player Le joueur présent sur la map
		 * \param items La liste des items présents sur la map
		 * \return true si la MoreLife doit être supprimé, false sinon
		 * 
		 * \author Hocine HADID
		 */
		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
};

#endif