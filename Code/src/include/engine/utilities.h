/**
 * \file utilities.h
 * \author Pierre CHEMIN
 * \brief Fichier contenant des éléments pouvant être utile de manière globale au projet
 * \version 0.1
 * \date 2022-04-06
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __UTILITIES__
#define __UTILITIES__

/**
 * \namespace utilities
 * 
 * Espace de nommage regroupant les éléments pouvant être utile de manière globale au projet 
 * 
 */
namespace utilities
{
	/**
	 * \brief Enumeration de direction
	 * 
	 * Enumeration pour clarifier la direction de déplacements
	 * 
	 */
	typedef enum
	{
		TOP, /*!< Direction vers le haut*/
		BOTTOM, /*!< Direction vers le bas*/
		LEFT, /*!< Direction vers la gauche*/
		RIGHT, /*!< Direction vers la droite*/
		NONE /*!< Aucune directon (pas de déplacement)*/
	}EDirection;

	/**
	 * \brief Enumeration de direction d'explosion
	 * 
	 * Enumeration pour clarifier l'orientation de l'explosion d'une bombe
	 * 
	 */
	typedef enum
	{
		LINE, /*!< Explosion en ligne par rapport au centre de l'explosion*/
		COLUMN, /*!< Explosion en colonne par rapport au centre de l'explosion*/
		CENTER, /*!< On se situe au centre de l'explosion*/
		NOEXPLOSION /*!< Il n'y a pas d'explosion*/
	}EBombExplosionDirection;
}

#endif