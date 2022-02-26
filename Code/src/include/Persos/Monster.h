#ifndef __MONSTER__
#define __MONSTER__

#include "Ennemy.h"

class Monster: public Ennemy
{
	public:
		Monster(int x, int y, int life, int speed, int damage);
		~Monster();

		void show() const;
};

#endif