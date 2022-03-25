#ifndef __BOWMAN__
#define __BOWMAN__

#include "Ennemy.h"
#include "../engine/utilities.h"
#include "../Items/Arrow.h"

class Bowman : public Ennemy
{	
	public:
		Bowman(int x, int y, int life, int speed, int damage);
		~Bowman();

		virtual void show() const override;

		Arrow shootArrow(utilities::EDirection) const;
		utilities::EDirection shootPlayer() const;
};

#endif