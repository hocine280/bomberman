#ifndef __GHOST__
#define __GHOST__

#include "Ennemy.h"

class Ghost: public Ennemy
{
	public:
		Ghost(int x, int y, int life, int speed, int damage, int still);
		~Ghost();

		virtual void show() const override;
};

#endif