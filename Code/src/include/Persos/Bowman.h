#ifndef __BOWMAN__
#define __BOWMAN__

#include "Ennemy.h"

class Bowman
{	
	public:
		Bowman(int x, int y, int life, int speed, int damage);
		~Bowman();

		void show() const;

		void shootArrow(DirectionEnum) const;
		DirectionEnum shootPlayer() const;
};

#endif