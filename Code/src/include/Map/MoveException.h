#ifndef __MOVEEXCEPTION__
#define __MOVEEXCEPTION__

#include <exception>

class MoveException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Déplacement impossible ! Sortie de map !";
		}
};

#endif