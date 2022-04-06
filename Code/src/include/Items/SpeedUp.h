/**
 * \file SpeedUp.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe SpeedUp
 * \version 0.1
 * \date 2022-04-06
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __SPEEDUP__
#define __SPEEDUP__

#include "Item.h"
#include "../Persos/Bomberman.h"

/**
 * \class SpeedUp
 * \brief La classe SpeedUp hérite de la classe Item et permets de gérer les items de type SpeedUp
 * \see Item
 * 
 * Permets de gérer les items de type SpeedUp qui permettent d'augmenter la vitesse du Bomberman
 * 
 * \author Hocine HADID
 */
class SpeedUp: public Item
{
	private:
		int m_speed; /*!< La vitesse qu'il faudra rajouter au Bomberman*/
		
	public:
		/**
		 * \brief Constructeur de la SpeedUp
		 * 
		 * \param x La ligne sur laquelle se situe la ScaleUp
		 * \param y La colonne sur laquelle se situe la ScaleUp
		 * \param speed La vitesse qui sera rajouté au joueur
		 */
		SpeedUp(int x = 0, int y = 0, int speed = 1);
		/**
		 * \brief Destructeur de la SpeedUp
		 * 
		 */
		~SpeedUp();
		
		/**
		 * \brief Rajoute la vitesse au Bomberman
		 * \see Bomberman
		 * 
		 * @param b Le bomberman auquelle il faut rajouter la vitesse
		 * 
		 * \author Hocine HADID
		 */
		void increaseSpeed(Bomberman* b);

		/**
		 * \brief Affiche la partie haute de la case lors de l'affichage de la SpeedUp
		 * 
		 * \author Hocine HADID
		 */
		void showTop() const override;
		/**
		 * \brief Affiche la partie du milieu de la case lors de l'affichage de la SpeedUp
		 * 
		 * \author Hocine HADID
		 */
		void showMiddle() const override;
		/**
		 * \brief Affiche la partie basse de la case lors de l'affichage de la Speedup
		 * 
		 * \author Hocine HADID
		 */
		void showBottom() const override;

		/**
		 * \brief Permet de jouer la Speedup
		 * \see Bomberman
		 * \see Item
		 * \see Tile
		 * 
		 * Joue la Speedup, si la Speedup est sur la même case que le joueur alors rajoute la vitesse précisé au joueur
		 * 
		 * \param map La map sur laquelle la Speedup est joué
		 * \param player Le joueur présent sur la map
		 * \param items La liste des items présents sur la map
		 * \return true si la Speedup doit être supprimé, false sinon
		 * 
		 * \author Hocine HADID
		 */
		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
};

#endif