/**
 * \file Map.h
 * \author Pierre CHEMIN & Hocine HADID
 * \brief Fichier contenant la classe Map
 * \version 0.1
 * \date 2022-03-12
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __MAP__
#define __MAP__

#include <vector>

#include "Tile.h"
#include "Position.h"
#include "Wall.h"

#include "../Persos/Ennemy.h"
#include "../Persos/Bomberman.h"

#include "../Items/Item.h"
#include "../Items/Bomb.h"

#include "../engine/utilities.h"

/**
 * \class Map
 * \brief La classe Map permets de gérer une map du jeu Bomberman
 * \see Bomberman
 * \see Tile
 * \see Ennemy
 * \see Item
 * \see Bomb
 * \see EBombExplosionDirection
 * 
 * 
 * \author Pierre CHEMIN & Hocine HADID
 */
class Map
{
	private:
		int m_nbColumn; /*!< Le nombre de colonne de la map*/
		int m_nbLine; /*!< Le nombre de ligne de la map*/
		Tile m_target; /*!< L'objectif que le joueur doit atteindre sur la map*/
		Bomberman m_player; /*!< Le joueur présent sur la map*/
		std::vector <std::vector<utilities::EBombExplosionDirection>>m_bombExplosion; /*!< Une version de la map qui permet de savoir sur quelles cases se situe l'explosion d'une bombe*/
		std::vector <std::vector<Tile*>>m_mapTile; /*!< Une version de la map sous forme de Tile qui permettra de gérer les déplacements et l'affichage des murs*/
		std::vector <Ennemy*> m_listEnnemy; /*!< La liste des ennemies présents sur la map*/
		std::vector <Item*> m_listItems; /*!< La liste des items présents sur la map*/
		std::vector <Bomb*> m_listBombs; /*!< La liste des bombes présentes sur la map*/

		/**
		 * \brief Permets de positionner sur quelles cases se situe l'explosion
		 * 
		 * \param positionExplosion La position centrale de l'explosion
		 * 
		 * \author Hocine HADID
		 */
		void bombExplosion(Position positionExplosion);

	public:
		Map(int level = 0);
		~Map();

		Tile getTarget() const;
		int getNbColumn() const;
		int getNbLine() const;
		Bomberman getPlayer() const;
		std::vector <Ennemy*> getListEnnemy() const;
		std::vector <Item*> getListItems() const;
		std::vector <Bomb*> getListBombs() const;

		/**
		 * \brief Permets de rajouter une bombe sur la map à la position du joueur
		 * 
		 * \author Pierre CHEMIN
		 */
		void playBomb();
		/**
		 * \brief Permets de remettre à 0 la map de l'explosion d'une bombe
		 * 
		 * \author Hocine HADID
		 */
		void eraseBombExplosion();

		/**
		 * \brief Permet l'affichage de la map sur la console
		 * 
		 * \author Pierre CHEMIN
		 */
		void showMap() const;

		/**
		 * \brief Permets de charger une map en fonction de son niveau
		 * 
		 * \param map Le niveau de la map à charger
		 * 
		 * \author Pierre CHEMIN
		 */
		void loadMap(int map);
		/**
		 * \brief Permets de déplacer le Bomberman dans une direction et un nombre de case précis
		 * \throw MoveException lève une exception si le déplacement ne peut être effectué pour quelconques raisons
		 * 
		 * \param direction La direction dans laquelle doit se déplacer le Bomberman
		 * \param nbCase Le nombre de case dont doit se déplacer le Bomberman
		 * \return true si le déplacement a bien été effectué, false sinon
		 * 
		 * \author Pierre CHEMIN
		 */
		bool movePlayer(utilities::EDirection direction, int nbCase);
		/**
		 * \brief Permets de jouer un ennemie précis sur la map
		 * 
		 * \param ennemy L'ennemie à faire joueur sur la map
		 * 
		 * \author Hocine HADID
		 */
		void playEnnemy(int ennemy);
		/**
		 * \brief Permets de jouer un item précis sur la map
		 * 
		 * \param item L'item à jouer sur la map
		 * 
		 * \author Hocine HADID
		 */
		void playItem(int item);
		/**
		 * \brief Permets de jouer une bombe présente sur la map
		 * 
		 * \param bomb La bombe à jouer sur la map
		 * 
		 * \author Hocine HADID
		 */
		void playBomb(int bomb);
};

#endif