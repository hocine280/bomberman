/**
 * \file Wall.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe Wall
 * \version 0.1
 * \date 2022-04-07
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __WALL__
#define __WALL__

#include "Tile.h"

/**
 * \class Wall
 * \brief La classe Wall hérite dec la classe Tile et permets de gérer les murs présents sur la map
 * \see Tile
 * 
 * \author Hocine HADID
 */
class Wall : public Tile
{
	private:
		bool m_destructible; /*!< Si le mur est destructible ou non*/
		int m_nbNecessaryBomb; /*!< Le nombre de bombe nécessaire pour détruire le mur*/

	public:
		/**
		 * \brief Constructeur d'un Wall
		 * 
		 * \param x La ligne sur laquelle se situe le Wall
		 * \param y La colonne sur laquelle se situe le Wall
		 * \param beCrossed Si c'est possible de traverser le Wall
		 * \param destructible Si le Wall est destructible ou non
		 * \param nbNecessaryBomb Le nombre de bombe nécessaire pour détruire le Wall
		 */
		Wall(int x = 0, int y = 0, bool beCrossed = false, bool destructible = true, int nbNecessaryBomb = 2);
		/**
		 * \brief Destructeur d'un Wall
		 * 
		 */
		~Wall();

		/**
		 * \brief Accesseur de l'attribut m_destructible
		 * 
		 * \return true si le Wall est destructible, false sinon
		 */
		bool getDestructible() const;
		/**
		 * \brief Accesseur de l'attribut m_nbNecessaryBomb
		 * 
		 * \return int Le nombre de bombe nécessaire pour détruire le Wall
		 */
		int getNbNecessaryBomb() const;
		/**
		 * \brief Permets d'afficher une Wall
		 * 
		 * Affiche le Wall, un caractère "W" pour les murs, "w" pour les murs ne nécessitant qu'une seule bombe pour être détruit et "I" pour les murs indestructibles
		 * 
		 * \author Hocine HADID
		 */
		virtual void show() const override;
		/**
		 * \brief Permets d'affaiblir un Wall
		 * 
		 * \author Hocine HADID
		 */
		void weaken();
};

#endif