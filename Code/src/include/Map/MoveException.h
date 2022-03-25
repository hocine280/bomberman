#ifndef __MOVEEXCEPTION__
#define __MOVEEXCEPTION__

#include <exception>
#include <string>

class MoveException: public std::exception
{
	private:
		char* m_message;

	public:
		MoveException(char* message): m_message(message){};

		virtual const char* what() const throw()
		{
			return m_message;
		}
};

#endif