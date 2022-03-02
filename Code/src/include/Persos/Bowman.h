#ifndef __BOWMAN__
#define __BOWMAN__

#include "Ennemy.h"
#include "../engine/utilities.h"

class Bowman
{	
	public:
		Bowman(int x, int y, int life, int speed, int damage);
		~Bowman();

		void show() const override;

		Arrow shootArrow(utilities::EDirection) const;
		utilities::EDirection shootPlayer() const;
};

#endif