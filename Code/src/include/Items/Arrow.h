/**
 * \file Arrow.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe Arrow
 * \version 0.1
 * \date 2022-04-06
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __ARROW__
#define __ARROW__

#include "Item.h"
#include "../engine/utilities.h"

/**
 * \class Arrow
 * \brief La classe Arrow hérite de la classe Item et gère les flèches lancées par le Bowman
 * \see Item
 * 
 * Permet de gérer les flèches présentes sur la Map
 * 
 * \author Hocine HADID
 */
class Arrow: public Item
{
	private:
		int m_speed; /*!< la vitesse de la flèche*/
		int m_damage; /*!< Les dégâts que font la flèche lorsqu'elle touche le Bomberman*/
		utilities::EDirection m_direction; /*!< La direction dans laquelle se déplace la flèche*/

	public:
		/**
		 * \brief Constructeur de la classe Arrow
		 * 
		 * \param x La ligne où se situe la flèche
		 * \param y La colonne où se situe la flèche
		 * \param speed La vitesse de la flèche
		 * \param damage Les dégâts de la flèche
		 * \param direction La direction de la flèche
		 * 
		 * \see utilities
		 * 
		 */
		Arrow(int x = 0, int y = 0, int speed = 1, int damage = 1, utilities::EDirection direction = utilities::EDirection::NONE);

		/**
		 * \brief Déplace la flèche
		 * 
		 * Permets de déplacer la flèche en fonction de direction et de sa vitesse
		 * 
		 * \author Hocine HADID
		 */
		void move();
		/**
		 * \brief Affiche la partie haute de la case lors de l'affichage de la flèche
		 * 
		 * \author Hocine HADID
		 */
		virtual void showTop() const override;
		/**
		 * \brief Affiche la partie du milieu de la case lors de l'affichage de la flèche
		 * 
		 * \author Hocine HADID
		 */
		virtual void showMiddle() const override;
		/**
		 * \brief Affiche la partie basse de la case lors de l'affichage de la flèche
		 * 
		 * \author Hocine HADID
		 */
		virtual void showBottom() const override;
		/**
		 * \brief Permet de jouer la flèche
		 * \see Bomberman
		 * \see Item
		 * \see Tile
		 * 
		 * Joue la flèche, vérifie si la flèche une fois déplacé est sur la même case que le Bomberman, si c'est le cas inflige des dégâts
		 * au Bomberman sinon vérifie si la flèche n'est pas sortie de la map ou si la case sur laquelle elle souhaite se déplacer est libre.
		 * Si la flèche serait encore dans la map et que la case est libre alors déplace la flèche.
		 * 
		 * \param map La map sur laquelle la flèche se déplace
		 * \param player Le joueur présent sur la map
		 * \param items la liste des items présents sur la map
		 * \return true si la flèche doit être supprimer sinon retourne false
		 * 
		 * \author Hocine HADID
		 */
		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
};

#endif