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
		Tile(int x = 0, int y = 0, bool beCrossed = true);
		~Tile();

		Position getPosition() const;
		void setBeCrossed(bool beCrossed);
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