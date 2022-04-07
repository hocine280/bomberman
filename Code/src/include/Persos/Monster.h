/**
 * \file Monster.h
 * \author Pierre CHEMIN
 * \brief Fichier contenant la classe Monster
 * \version 0.1
 * \date 2022-04-07
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __MONSTER__
#define __MONSTER__

#include "Ennemy.h"

/**
 * \class Monster
 * \brief La classe Monster hérite de la classe Ennemy et permets de gérer les ennemies de type Monster
 * \see Ennemy
 * 
 * Permets de gérer un ennemie de type Monster, il s'agit d'un ennemie basique
 * 
 * \author Pierre CHEMIN
 */
class Monster: public Ennemy
{
	public:
		/**
		 * \brief Constructeur d'un Monster
		 * 
		 * \param x La ligne sur laquelle se situe le Monster
		 * \param y La colonne sur laquelle se situe le Monster
		 * \param life Le nombre de point de vie de le Monster
		 * \param speed La vitesse de le Monster
		 * \param damage Les dégâts qu'inflie le Monster
		 * \param still Le nombre de tour à patienter par le Monster avant de jouer
		 */
		Monster(int x, int y, int life, int speed, int damage, int still);
		/**
		 * \brief Destructeur d'un Monster
		 * 
		 */
		~Monster();

		/**
		 * \brief Permets d'afficher le Monster
		 * 
		 * Affiche le Monster, le caractère "M"
		 * 
		 * \author Pierre CHEMIN
		 */
		virtual void show() const override;
};

#endif