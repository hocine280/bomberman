/**
 * \file Position.h
 * \author Hocine HADID
 * \brief Fichier contenant la classe Position
 * \version 0.1
 * \date 2022-04-07
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __POSITION__
#define __POSITION__

/**
 * \class Position
 * \brief La classe Position permets de définir une position
 * 
 * Permets de définir une position sur un axe X et Y
 * 
 * \author Hocine HADID
 */
class Position
{
	private:
		int m_x; /*!< L'axe X (ou la ligne) de la position*/
		int m_y; /*!< L'axe Y (ou la colonne) de la position*/
		
	public:
		/**
		 * \brief Constructeur d'un Position
		 * 
		 * \param x L'axe X (ou la ligne) de la Position
		 * \param y L'axe Y (ou la colonne) de la Position
		 */
		Position(int x = 0, int y = 0);
		/**
		 * \brief Accesseur de l'attribut m_x
		 * 
		 * \return int L'axe X (ou la ligne) de la Position
		 */
		int getX() const;
		/**
		 * \brief Accesseur de l'attribut m_y
		 * 
		 * \return int L'axe Y (ou la colonne) de la Position
		 */
		int getY() const;
		/**
		 * \brief Accesseur de l'attribut m_x
		 * 
		 * \param x La nouvelle valeur de m_x
		 */
		void setX(int x);
		/**
		 * \brief Accesseur de l'attribut m_y
		 * 
		 * \param y La nouvelle valeur de m_y
		 */
		void setY(int y);

		/**
		 * \brief Surcharge de l'opérateur de comparaison, il permet de vérifier si deux Positions sont égales ou non
		 * 
		 * \param other La position qu'il faut comparé avec la position courante
		 * \return true si les positions comparées sont égales, false sinon
		 * 
		 * \author Hocine HADID
		 */
		bool operator==(const Position& other);
		/**
		 * \brief Surcharge de l'opérateur de différence, il permet de vérifier si deux Positions sont différentes ou non
		 * 
		 * \param other La position qu'il faut comparé avec la position courante
		 * \return true si les positions comparées sont différentes, false sinon
		 * 
		 * \author Hocine HADID
		 */
		bool operator!=(const Position& other);
};

#endif