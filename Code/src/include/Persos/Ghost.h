#ifndef __GHOST__
#define __GHOST__

#include "Ennemy.h"
#include "Bomberman.h"

class Ghost: public Ennemy
{
	public:
		Ghost(int x, int y, int life, int speed, int damage, int still);
		~Ghost();

		virtual utilities::EDirection play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
		virtual void show() const override;
};

#endif