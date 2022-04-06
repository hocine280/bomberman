/**
 * \file ScaleUp.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe ScaleUp
 * \version 0.1
 * \date 2022-04-06
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __SCALEUP__
#define __SCALEUP__

#include "Item.h"

/**
 * \class ScaleUp
 * \brief La classe ScaleUp hérite de la classe Item et permets de gérer les items de type ScaleUp
 * \see Item
 * 
 * Permets de gérer les items de type ScaleUp qui permettent d'augmenter la portée des bombes
 * 
 * \author Hocine HADID
 */
class ScaleUp: public Item
{
	private:
		double m_scope; /*!< La porté qui sera ajouté à la porté des bombes*/
		
	public:
		/**
		 * \brief Constructeur d'un item ScaleUp
		 * 
		 * \param x La ligne sur laquelle se situe la ScaleUp
		 * \param y La colonne sur laquelle se situe la ScaleUp
		 * \param scope La porté qui sera rajouté à la porté des bombes
		 */
		ScaleUp(int x = 0, int y = 0, double scope = 0.5);
		/**
		 * \brief Destructeur de la ScaleUp
		 * 
		 */
		~ScaleUp();

		/**
		 * \brief Rajoute la porté précisé aux bombes
		 * 
		 * \author Hocine HADID
		 */
		void increaseScope();

		/**
		 * \brief Affiche la partie haute de la case lors de l'affichage de la ScaleUp
		 * 
		 * \author Hocine HADID
		 */
		void showTop() const override;
		/**
		 * \brief Affiche la partie du milieu de la case lors de l'affichage de la ScaleUp
		 * 
		 * \author Hocine HADID
		 */
		void showMiddle() const override;
		/**
		 * \brief Affiche la partie basse de la case lors de l'affichage de la ScaleUp
		 * 
		 * \author Hocine HADID
		 */
		void showBottom() const override;

		/**
		 * \brief Permet de jouer la ScaleUp
		 * \see Bomberman
		 * \see Item
		 * \see Tile
		 * 
		 * Joue la ScaleUp, si la ScaleUp est sur la même case que le joueur alors rajoute la porté précisé aux bombes
		 * 
		 * \param map La map sur laquelle la ScaleUp est joué
		 * \param player Le joueur présent sur la map
		 * \param items La liste des items présents sur la map
		 * \return true si la ScaleUp doit être supprimé, false sinon
		 * 
		 * \author Hocine HADID
		 */
		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
};

#endif