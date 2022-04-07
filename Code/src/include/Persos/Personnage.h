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
		/**
		 * \brief Constructeur d'un Personnage
		 * 
		 * \param x La ligne sur laquelle se situe le Personnage
		 * \param y La colonne sur laquelle se situe le Personnage
		 * \param life Le nombre de point de vie du Personnage
		 * \param speed La vitesse du Personnage
		 */
		Personnage(int x=0, int y=0, int life = 3, int speed = 1);
		/**
		 * \brief Destructeur d'un Personnage
		 * 
		 */
		~Personnage();

		/**
		 * \brief Accesseur de l'attribut m_position
		 * 
		 * \return Position La position du Personnage
		 */
		Position getPosition() const;
		/**
		 * \brief Accesseur de l'attribut m_life
		 * 
		 * \return int Le nombre de point de vie restant du Personnage
		 */
		int getLife() const;
		/**
		 * \brief Accesseur de l'attribut m_speed
		 * 
		 * \return int La vitesse du Personnage
		 */
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