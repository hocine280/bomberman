#ifndef __BOWMAN__
#define __BOWMAN__

#include "Ennemy.h"
#include "../engine/utilities.h"
#include "../Items/Arrow.h"

class Bowman : public Ennemy
{	
	private:
		Arrow shootArrow(utilities::EDirection) const;

	public:
		Bowman(int x, int y, int life, int speed, int damage, int still);
		~Bowman();

		virtual void show() const override;

		virtual utilities::EDirection play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
		utilities::EDirection shootPlayer(Bomberman *player) const;
};

#endif