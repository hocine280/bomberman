/**
 * \file MoveException.h
 * \author Pierre CHEMIN
 * \brief Fichier contenant la classe MoveException
 * \version 0.1
 * \date 2022-04-08
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef __MOVEEXCEPTION__
#define __MOVEEXCEPTION__

#include <exception>
#include <string>

/**
 * \class MoveException
 * \brief La classe MoveException hérite de la classe std::exception
 * 
 * Permets de gérer les exceptions de déplacement
 * 
 * \author Pierre CHEMIN
 */
class MoveException: public std::exception
{
	private:
		std::string m_message; /*!< Le message de l'exception*/

	public:
		/**
		 * \brief Constructeur de la MoveException
		 * 
		 * \param message Le message à afficher par l'exception
		 */
		MoveException(std::string message): m_message(message){};
		/**
		 * \brief Permets de savoir pourquoi l'exception est levé
		 * 
		 * \return char* Le message dec l'exception à afficher à l'utilisateur
		 */
		virtual const char* what() const throw()
		{
			return m_message.c_str();
		}
};

#endif