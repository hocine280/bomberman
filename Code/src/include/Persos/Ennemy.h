#ifndef __ENNEMY__
#define __ENNEMY__

#include "../Map/Position.h"
#include "Personnage.h"

#include "../engine/utilities.h"

class Ennemy: public Personnage
{
	protected:
		int m_damage;
		
	public:
		Ennemy(int x, int y, int life, int speed, int damage);
		~Ennemy();

		int getDamage() const;
		void setDamage(int);

		virtual void play(utilities::EDirection direction);
};

#endif