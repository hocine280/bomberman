/**
 * \file Bomberman.h
 * \author Pierre CHEMIN
 * \brief Fichier contenant la classe Bomberman
 * \version 0.1
 * \date 2022-04-07
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __BOMBERMAN__
#define __BOMBERMAN__

#include "Personnage.h"
#include "../Map/Position.h"

/**
 * \class Bomberman
 * \brief La classe Bomberman hérite de la classe Personnage et permets de gérer un Bomberman (le joueur)
 * \see Personnage
 * 
 * Permets de gérer un Bomberman, il s'agit également du joueur d'une partie
 * 
 * \author Pierre CHEMIN
 */
class Bomberman: public Personnage
{
	private:
		int m_bombMax; /*!< Le nombre de bombe maximale que peut possèder un Bomberman*/
		int m_nbBomb; /*!< Le nombre de bombe possédée par un Bomberman*/

	public:
		/**
		 * \brief Constructeur d'un Bomberman
		 * 
		 * \param x La ligne sur laquelle se situe le Bomberman
		 * \param y La colonne sur laquelle se situe le Bomberman
		 * \param life Le nombre de point de vie du Bomberman
		 * \param speed La vitesse du Bomberman
		 * \param bombMax Le nombre de bombe maximal du Bomberman
		 * \param nbBomb Le nombre de bombe en possession du Bomberman
		 */
		Bomberman(int x=0, int y=0, int life=3, int speed=1, int bombMax=5, int nbBomb=2);
		/**
		 * \brief Destructeur du Bomberman
		 * 
		 */
		~Bomberman();

		/**
		 * \brief Accesseur de l'attribut m_bombMax
		 * 
		 * \return int Le nombre de bombe maximal du Bomberman
		 */
		int getBombMax() const;
		/**
	 * \brief Accesseur de l'attribut m_nbBomb
		 * 
		 * @return int Le nombre de bombe maximal du Bomberman
		 */
		int getNbBomb() const;
		/**
		 * \brief Permets d'ajouter des bombes au Bomberman
		 * 
		 * Si le nombre de bombe est supérieur au nombre de bombe maximale alors mets le nombre de bombe au maximum
		 * 
		 * \param nbBomb Le nombre de bombe a ajouté 
		 * \author Pierre CHEMIN
		 */
		void addBomb(int nbBomb);
		/**
		 * \brief Permets d'ajouter de la vie au Bomberman
		 * 
		 * \param life Le nombre de point de vie à ajouter au Bomberman
		 * \author Pierre CHEMIN
		 */
		void addLife(int life);
		/**
		 * \brief Permets d'ajouter de la vitesse au Bomberman
		 * 
		 * \param speed La vitesse à ajouter au Bomberman
		 * \author Pierre CHEMIN
		 */
		void addSpeed(int speed);
		/**
		 * \brief Permets de retirer une bombe au Bomberman
		 * 
		 * \author Pierre CHEMIN
		 */
		void dropBomb();
		/**
		 * \brief Permets de déplacer le Bomberman dans une direction précise
		 * \see Edirection
		 * 
		 * \param direction La direction dans laquelle doit se déplacer le Bomberman
		 * \return true si le déplacement a pu se faire, false sinon
		 * 
		 * \author Pierre CHEMIN
		 */
		virtual bool move(utilities::EDirection direction);
		/**
		 * \brief Permets de déplacer le Bomberman dans une direction et une vitesse précise
		 * \see EDirection
		 * 
		 * \param direction La direction dans laquelle doit se déplacer le Bomberman
		 * \param speed La vitesse avec laquelle le Bomberman doit se déplacer
		 * \return true si le déplacement a pu se faire, false sinon
		 */
		bool move(utilities::EDirection direction, int speed);
		/**
		 * \brief Permets d'afficher le Bomberman
		 * 
		 * Affiche le Bomberman, le caractère "P"
		 * 
		 * \author Pierre CHEMIN
		 */
		virtual void show() const override;
};

#endif