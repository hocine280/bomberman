/**
 * \file Arrow.h
 * \author Hocine HADID
 * \brief 
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
 * \brief La classe Arrow étend la classe Item et gère les flèches lancés par le Bowman
 * \see Item
 * 
 * Permet de gérer les flèches présentes sur la Map
 * 
 */
class Arrow: public Item
{
	private:
		int m_speed; /*!< la vitesse de la flèche*/
		int m_damage; /*!< Les dégâts que font la flèche lorsqu'elle touche le Bomberman*/
		utilities::EDirection m_direction; /*!< La direction dans laquelle se déplace la flèche*/

	public:
		Arrow(int x = 0, int y = 0, int speed = 1, int damage = 1, utilities::EDirection direction = utilities::EDirection::NONE);

		void move();
		virtual void showTop() const override;
		virtual void showMiddle() const override;
		virtual void showBottom() const override;

		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
};

#endif