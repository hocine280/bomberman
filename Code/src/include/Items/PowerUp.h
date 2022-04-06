/**
 * \file PowerUp.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe PowerUp
 * \version 0.1
 * \date 2022-04-06
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __POWERUP__
#define __POWERUP__

#include "Item.h"
#include "../Persos/Bomberman.h"

/**
 * \class PowerUp
 * \brief La classe PowerUp hérite de la classe Item et permets de gérer les items de type PowerUp
 * \see Item
 * 
 * Permets de gérer les items de type MoreLife qui permettent d'augmenter la puissance des bombes
 * 
 * \author Hocine HADID
 */
class PowerUp: public Item
{
	private:
		int m_powerPoint; /*!< La puissance dont vont augmenter les bombes*/
		
	public:
		/**
		 * \brief Constructeur d'un item PowerUp
		 * 
		 * \param x La ligne sur laquelle se situe la PowerUp
		 * \param y La colonne sur laquelle se situe la PowerUp
		 * \param powerPoint La puissance que rajoutera l'item aux bombes
		 */
		PowerUp(int x = 0, int y = 0, int powerPoint = 1);
		/**
		 * \brief Destructeur de la PowerUp
		 * 
		 */
		~PowerUp();

		/**
		 * \brief Rajoute la puissance précisé aux bombes
		 * 
		 * \author Hocine HADID
		 */
		void increasePower();
		/**
		 * \brief Affiche la partie haute de la case lors de l'affichage de la PowerUp
		 * 
		 * \author Hocine HADID
		 */
		void showTop() const override;
		/**
		 * \brief Affiche la partie du milieu de la case lors de l'affichage de la PowerUp
		 * 
		 * \author Hocine HADID
		 */
		void showMiddle() const override;
		/**
		 * \brief Affiche la partie basse de la case lors de l'affichage de la PowerUp
		 * 
		 * \author Hocine HADID
		 */
		void showBottom() const override;

		/**
		 * \brief Permet de jouer la PowerUp
		 * \see Bomberman
		 * \see Item
		 * \see Tile
		 * 
		 * Joue la PowerUp, si la PowerUp est sur la même case que le joueur alors rajoute la puissance précisé aux bombes
		 * 
		 * \param map La map sur laquelle la PowerUp est joué
		 * \param player Le joueur présent sur la map
		 * \param items La liste des items présents sur la map
		 * \return true si la PowerUp doit être supprimé, false sinon
		 * 
		 * \author Hocine HADID
		 */
		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
};

#endif