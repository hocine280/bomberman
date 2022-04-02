#ifndef __PERSONNAGE__
#define __PERSONNAGE__

#include "../Map/Position.h"
#include "../engine/utilities.h"

class Personnage
{
	protected:
		Position m_position;
		int m_life, m_speed;
		
	public:
		Personnage(int x=0, int y=0, int life = 3, int speed = 1);
		~Personnage();

		Position getPosition() const;
		int getLife() const;
		int getSpeed() const;
		void receiveDamage(int damage);
		virtual bool move(utilities::EDirection direction);
		virtual void show() const = 0;
};

#endif