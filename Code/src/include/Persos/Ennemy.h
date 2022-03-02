#ifndef __ENNEMY__
#define __ENNEMY__

#include "../Map/Position.h"
#include "Personnage.h"

class Ennemy: public Personnage
{
	protected:
		int m_damage;
		
	public:
		Ennemy(int x, int y, int life, int speed, int damage);
		~Ennemy();

		int getDamage() const;
		void setDamage(int);
};

#endif