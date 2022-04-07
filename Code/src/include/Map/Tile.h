/**
 * \file Tile.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe Tile
 * \version 0.1
 * \date 2022-04-07
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __TILE__
#define __TILE__

#include "Position.h"

/**
 * \class Tile
 * \brief La classe Tile permets de définir une case de la map
 * \see Position
 * 
 * \author Hocine HADID
 */
class Tile
{
	private:
		Position m_position; /*!< La position de la tile*/
		bool m_beCrossed; /*!< Indique si la case peut être traversée ou non*/

	public:
		/**
		 * \brief Constructeur d'une Tile
		 * 
		 * \param x La ligne sur laquelle se situe la Tile
		 * \param y La colonne sur laquelle se situe la Tile
		 * \param beCrossed Si c'est possible de traverser la Tile
		 */
		Tile(int x = 0, int y = 0, bool beCrossed = true);
		/**
		 * \brief Destructeur d'une Tile
		 * 
		 */
		~Tile();

		/**
		 * \brief Accesseur de l'attribut m_position
		 * 
		 * \return Position La position de la Tile
		 */
		Position getPosition() const;
		/**
		 * \brief Accesseur de l'attribut m_beCrossed
		 * 
		 * \param beCrossed si c'est possible de traverser la Tile ou non
		 */
		void setBeCrossed(bool beCrossed);
		/**
		 * \brief Accesseur de l'attribut m_beCrossed
		 * 
		 * \return bool La possibilité de traverser la Tile ou non
		 */
		bool getBeCrossed() const;
		/**
		 * \brief Permets d'afficher une Tile
		 * 
		 * Affiche la Tile, un espace
		 * 
		 * \author Hocine HADID
		 */
		virtual void show() const;
		
};

#endif