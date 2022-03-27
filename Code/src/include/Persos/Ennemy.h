#ifndef __ENNEMY__
#define __ENNEMY__

#include "../Map/Position.h"
#include "../Map/Map.h"
#include "Personnage.h"

#include "../engine/utilities.h"

class Ennemy: public Personnage
{
	protected:
		int m_damage;
		int m_still;
		
	public:
		Ennemy(int x, int y, int life, int speed, int damage, int still);
		~Ennemy();

		int getDamage() const;
		void setDamage(int);

		//virtual void play(Map map);
};

#endif