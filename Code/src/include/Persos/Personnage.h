#ifndef __PERSONNAGE__
#define __PERSONNAGE__

#include "../Map/Position.h"

class Personnage
{
	private:
		Position m_position;
		int m_life, m_speed;
		
	public:
		Personnage(Position position = Position(), int life = 3, int speed = 1);

		Position getPosition() const;
		int getLife() const;
		int getSpeed() const;
		bool move(DirectionEnum direction);
		void show() const;
};

#endif