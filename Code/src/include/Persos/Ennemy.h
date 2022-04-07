/**
 * \file Ennemy.h
 * \author Pierre CHEMIN
 * \brief Fichier contenant la classe Ennemy
 * \version 0.1
 * \date 2022-04-07
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __ENNEMY__
#define __ENNEMY__

#include "Personnage.h"
#include "Bomberman.h"

#include "../Map/Position.h"
#include "../Map/Tile.h"

#include "../Items/Item.h"

#include "../engine/utilities.h"

#include <vector>

/**
 * \class Ennemy
 * \brief La classe abstraite Ennemy qui hérite de la classe Personnage
 * \see Ennemy
 * 
 * Permets de définir un Ennemy
 * 
 * \author Pierre CHEMIN
 */
class Ennemy: public Personnage
{
	protected:
		int m_damage; /*!< Les dégâts infligés par un Ennemy*/
		int m_still; /*!< Le nombre de tour durant lequel un Ennemy ne peut jouer */
		
	public:
		Ennemy(int x, int y, int life, int speed, int damage, int still);
		~Ennemy();

		int getDamage() const;
		void setDamage(int);

		/**
		 * \brief Permets de faire jouer un Ennemy
		 * 
		 * Déplace un Ennemy en fonction de la position du joueur et si la case est accessible
		 * 
		 * \param map La map de Tile sur laquelle l'Ennemy se déplace
		 * \param player Le joueur présent dans la partie
		 * \param items La liste des items de la partie
		 * \return utilities::EDirection La direction dans laquelle se déplace l'Ennemy
		 */
		virtual utilities::EDirection play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items);
};

#endif