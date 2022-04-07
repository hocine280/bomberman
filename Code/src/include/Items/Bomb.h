/**
 * \file Bomb.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe Bomb
 * \version 0.1
 * \date 2022-04-06
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __BOMB__
#define __BOMB__

#include "Item.h"

/**
 * \class Bomb
 * \brief La classe Bomb hérite de la classe Item et permets de gérer les flèches
 * \see Item
 * 
 * Permet de gérer les bombes posées par le Bomberman
 * 
 * \author Hocine HADID
 */
class Bomb: public Item
{
	private:
		int m_turnBeforeExplosion; /*!< Le nombre de tour avant l'explosion de la bombe*/
		
	public:
		static int power; /*!< La puissance de la bombe*/
		static double scope; /*!< La portée de la bombe*/

		/**
		 * \brief Constructeur d'une Bombe
		 * 
		 * \param x La ligne sur laquelle se situe la bombe
		 * \param y La colonne sur laquelle se situe la bombe
		 * \param turnBeforeExplosion Le nombre de tour restant avant l'explosion de la bombe
		 */
		Bomb(int x = 0, int y = 0, int turnBeforeExplosion = 3);
		/**
		 * \brief Destructeur de la bombe
		 * 
		 */
		~Bomb();

		/**
		 * @brief accesseur de l'attribut scope
		 * 
		 * @return double La porté de la bombe
		 */
		double getScope() const;
		/**
		 * @brief accesseur de l'attribut turnBeforeExplosion
		 * 
		 * @return int Le nombre de tour avant l'explosion de la bombe
		 */
		int getTurnBeforeExplosion() const;

		/**
		 * \brief décrémente le nombre de tour avant l'explosion de la bombe
		 * 
		 * \author Hocine HADID
		 */
		void decreaseTurnBeforeExplosion();

		/**
		 * \brief Affiche la partie haute de la case lors de l'affichage de la bombe
		 * 
		 * \author Hocine HADID
		 */
		void showTop() const override;
		/**
		 * \brief Affiche la partie du milieu de la case lors de l'affichage de la bombe
		 * 
		 * \author Hocine HADID
		 */
		void showMiddle() const override;
		/**
		 * \brief Affiche la partie basse de la case lors de l'affichage de la bombe
		 * 
		 * \author Hocine HADID
		 */
		void showBottom() const override;

		/**
		 * \brief Permet de jouer la bombe
		 * \see Bomberman
		 * \see Item
		 * \see Tile
		 * 
		 * Joue la bombe, si le nombre de tour est supérieur à 0, appelle la méthode decreaseTurnBeforeExplosion.
		 * 
		 * \param map La map sur laquelle la bombe est joué
		 * \param player Le joueur présent sur la map
		 * \param items La liste des items présents sur la map
		 * \return true si la bombe doit être supprimé, false sinon
		 * 
		 * \author Hocine HADID
		 */
		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
};

#endif