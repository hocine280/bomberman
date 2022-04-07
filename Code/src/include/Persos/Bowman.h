/**
 * \file Bowman.h
 * \author Pierre CHEMIN
 * \brief Fichier contenant la classe Bowman
 * \version 0.1
 * \date 2022-04-07
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __BOWMAN__
#define __BOWMAN__

#include "Ennemy.h"
#include "../engine/utilities.h"
#include "../Items/Arrow.h"

/**
 * \class Bowman
 * \brief La classe Bowman hérite de la classe Ennemy et permets de gérer les ennemies de type Bowman
 * \see Ennemy
 * 
 * Permets de gérer un ennemie de type Bowman, il s'agit d'un ennemie pouvant lancer des flèches en direction du joueur
 * 
 * \author Pierre CHEMIN
 */
class Bowman : public Ennemy
{	
	private:
		/**
		 * \brief Lance une flèche dans la direction précisé
		 * \see Arrow
		 * 
		 * Permets de faire lancer une flèche par le Bowman dans la direction précisée
		 * 
		 * \param direction La direction dans laquelle la flèche est lancée
		 * \return Arrow La flèche lancée
		 * 
		 * \author Pierre CHEMIN
		 */
		Arrow shootArrow(utilities::EDirection direction) const;

	public:
		/**
		 * \brief Constructeur d'un Bowman
		 * 
		 * \param x La ligne sur laquelle se situe le Bowman
		 * \param y La colonne sur laquelle se situe le Bowman
		 * \param life Le nombre de point de vie du Bowman
		 * \param speed La vitesse du Bowman
		 * \param damage Les dagâts qu'inflige le Bowman
		 * \param still Le nombre de tour à patienter par le Bowman avant de jouer
		 */
		Bowman(int x, int y, int life, int speed, int damage, int still);
		/**
		 * \brief Destructeur d'un Bowman
		 * 
		 */
		~Bowman();
		
		/**
		 * \brief Permets d'afficher le Bowman
		 * 
		 * Affiche le Bowman, le caractère "B"
		 * 
		 * \author Pierre CHEMIN
		 */	
		virtual void show() const override;

		/**
		 * \brief Permets de faire jouer un Bowman
		 * 
		 * Déplace un Bowman en fonction de la position du joueur sauf s'il peut tirer une flèche en direction du joueur et si c'est le cas le fait
		 * 
		 * \param map La map de Tile sur laquelle le Bowman se déplace
		 * \param player Le joueur présent dans la partie
		 * \param items La liste des items de la partie
		 * \return utilities::EDirection La direction dans laquelle se déplace le Bowman
		 * 
		 * \author Pierre CHEMIN
		 */
		
		virtual utilities::EDirection play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
		/**
		 * \brief Permets de savoir si l'on peut lancer une flèche sur le joueur et dans quelle direction
		 * 
		 * \param player Le joueur qu'il faut viser
		 * \return utilities::EDirection La direction dans laquelle se situe le joueur si on peut lui lancer une flèche
		 * 
		 * \author Pierre CHEMIN
		 */
		utilities::EDirection shootPlayer(Bomberman *player) const;
};

#endif