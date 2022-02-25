#ifndef __PERSONNAGE__
#define __PERSONNAGE__

#include "../Map/Position.h"
#include "DirectionEnum.h"

class Personnage
{
	protected:
		Position m_position;
		int m_life, m_speed;
		
	public:
		Personnage(Position position = Position position(), int life = 3, int speed = 1);
		~Personnage();

		Position getPosition() const;
		int getLife() const;
		int getSpeed() const;
		bool move(DirectionEnum direction);
		virtual void show() const = 0;
};

#endif