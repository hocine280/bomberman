/**
 * \file Map.h
 * \author Pierre CHEMIN & Hocine HADID
 * \brief 
 * \version 0.1
 * \date 2022-03-12
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __MAP__
#define __MAP__

#include <vector>

#include "../Persos/Bomberman.h"
#include "Tile.h"
#include "../Items/Item.h"
#include "../Persos/Ennemy.h"
#include "Wall.h"

class Map
{
	private:
		int m_nbColumn;
		int m_nbLine;
		Tile m_target;
		Bomberman m_player;
		std::vector <std::vector<Tile*>>m_mapTile;
		std::vector <Ennemy*> m_listEnnemy;
		std::vector <Item*> m_listItems;

	public:
		Map(int level = 0);
		~Map();

		/**
		 * \brief Get the Target object
		 * 
		 * \return Tile the target
		 */
		Tile getTarget() const;

		/**
		 * \brief Get the Nb Column object
		 * 
		 * \return int the Nb Column
		 */
		int getNbColumn() const;
		
		/**
		 * \brief Get the Nb Line object
		 * 
		 * @return int the Nb Line 
		 */
		int getNbLine() const;

		Bomberman getPlayer() const;

		std::vector <Ennemy*> getListEnnemy() const;

		/**
		 * \brief Permet l'affichage de la map sur la console
		 * \author Pierre CHEMIN
		 * 
		 */
		void showMap() const;

		void loadMap(int map);

		bool movePlayer(utilities::EDirection direction);

		void moveEnnemy(int ennemy);
};

#endif