/**
 * \file Personnage.h
 * \author Pierre CHEMIN
 * \brief Fichier contenant la classe Personnage
 * \version 0.1
 * \date 2022-04-07
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __PERSONNAGE__
#define __PERSONNAGE__

#include "../Map/Position.h"
#include "../engine/utilities.h"

/**
 * \class Personnage
 * \brief La classe abstraite personnage
 * \see Position
 * 
 * Permets de définir un personnage
 * 
 * \author Pierre CHEMIN
 */
class Personnage
{
	protected:
		Position m_position; /*!< La position du personnage*/
		int m_life; /*!< La vie du personnage*/
		int m_speed; /*!< La vitesse du personnage*/
		
	public:
		Personnage(int x=0, int y=0, int life = 3, int speed = 1);
		~Personnage();

		Position getPosition() const;
		int getLife() const;
		int getSpeed() const;
		/**
		 * \brief Lorsque le personnage reçoit des dégâts
		 * 
		 * Permets d'infliger des dégâts au personnage
		 * 
		 * \param damage Le nombre de dégât infligé
		 * \author Pierre CHEMIN
		 */
		void receiveDamage(int damage);
		/**
		 * \brief Permets de déplacer un personnage
		 * \see EDirection
		 * 
		 * \param direction La direction dans laquelle doit se déplacer le personnage
		 * \return true si le déplacement a pu se faire, false sinon
		 * 
		 * \author Pierre CHEMIN
		 */
		virtual bool move(utilities::EDirection direction);
		/**
		 * \brief Permets d'afficher le personnage
		 * \author Pierre CHEMIN
		 */
		virtual void show() const = 0;
};

#endif