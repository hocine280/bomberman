/**
 * \file Item.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe Item
 * \version 0.1
 * \date 2022-04-06
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __ITEM__
#define __ITEM__

#include "../Map/Position.h"
#include "../Map/Tile.h"

#include "../Persos/Bomberman.h"

#include <vector>

/**
 * \class Item
 * \brief La classe abstraite Item
 * \see Position
 * 
 * Permet de définir les différents items
 * 
 * \author Hocine HADID
 */
class Item
{
	protected:
		Position m_position; /*!< La position de l'item*/
		
	public:
		/**
		 * \brief Constructeur de la classe Item
		 * 
		 * \param x La ligne sur laquelle se situe l'objet
		 * \param y La colonne sur laquelle se situe l'objet
		 */
		Item(int x = 0, int y = 0);
		/**
		 * \brief Destructeur de la classe Item
		 * 
		 */
		~Item();

		/**
		 * \brief accesseur sur l'attribut position
		 * 
		 * @return Position La position de l'item
		 */
		Position getPosition() const;
		/**
		 * \brief Affiche la partie haute de la case lors de l'affichage de l'item
		 * 
		 * \author Hocine HADID
		 */
		virtual void showTop() const = 0;
		/**
		 * \brief Affiche la partie du milieu de la case lors de l'affichage de l'item
		 * 
		 * \author Hocine HADID
		 */
		virtual void showMiddle() const = 0;
		/**
		 * \brief Affiche la partie basse de la case lors de l'affichage de l'item
		 * 
		 * \author Hocine HADID
		 */
		virtual void showBottom() const = 0;

		/**
		 * \brief Permet de jouer un item
		 * \see Bomberman
		 * \see Item
		 * \see Tile
		 * 
		 * \param map La map sur laquelle l'item se situe
		 * \param player Le joueur présent sur la map
		 * \param items La liste des items présents sur la map
		 * \return true si l'item doit être supprimé, false sinon
		 * 
		 * \author Hocine HADID
		 */
		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) = 0;
};


#endif