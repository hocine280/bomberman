/**
 * \file Ghost.h
 * \author Pierre CHEMIN
 * \brief Fichier contenant la classe Ghost
 * \version 0.1
 * \date 2022-04-07
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __GHOST__
#define __GHOST__

#include "Ennemy.h"
#include "Bomberman.h"

/**
 * \class Ghost
 * \brief La classe Ghost hérite de la classe Ennemy et permets de gérer les ennemies de type Ghost
 * \see Ennemy
 * 
 * Permets de gérer un ennemie de type Ghost, il s'agit d'un ennemie pouvant traverser toutes les cases même celle occupé
 * 
 * \author Pierre CHEMIN
 */
class Ghost: public Ennemy
{
	public:
		/**
		 * \brief Constructeur d'un Ghost
		 * 
		 * \param x La ligne sur laquelle se situe le Ghost
		 * \param y La colonne sur laquelle se situe le Ghost
		 * \param life Le nombre de point de vie de le Ghost
		 * \param speed La vitesse de le Ghost
		 * \param damage Les dégâts qu'inflie le Ghost
		 * \param still Le nombre de tour à patienter par le Ghost avant de jouer
		 */
		Ghost(int x, int y, int life, int speed, int damage, int still);
		/**
		 * \brief Destructeur d'un Ghost
		 * 
		 */
		~Ghost();

		/**
		 * \brief Permets de faire jouer un Ghost
		 * 
		 * Déplace un Ghost en fonction de la position du joueur
		 * 
		 * \param map La map de Tile sur laquelle le Ghost se déplace
		 * \param player Le joueur présent dans la partie
		 * \param items La liste des items de la partie
		 * \return utilities::EDirection La direction dans laquelle se déplace le Ghost
		 * 
		 * \author Pierre CHEMIN
		 */
		virtual utilities::EDirection play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
		/**
		 * \brief Permets d'afficher le Ghost
		 * 
		 * Affiche le Ghost, le caractère "G"
		 * 
		 * \author Pierre CHEMIN
		 */
		virtual void show() const override;
};

#endif