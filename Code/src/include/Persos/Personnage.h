#ifndef __PERSONNAGE__
#define __PERSONNAGE__

#include "../Map/Position.h"

class Personnage
{
	private:
		Position m_position;
		int m_life, m_speed;
		
	public:
		Personnage();

		Position getPosition() const;
		int getLife() const;
		int getSpeed() const;
		bool move(DirectionEnum);
		void show() const;
};

#endif