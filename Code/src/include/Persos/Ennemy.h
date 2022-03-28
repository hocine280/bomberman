#ifndef __ENNEMY__
#define __ENNEMY__

#include "Personnage.h"
#include "Bomberman.h"

#include "../Map/Position.h"
#include "../Map/Tile.h"

#include "../Items/Item.h"

#include "../engine/utilities.h"

#include <vector>

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

		virtual utilities::EDirection play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items);
};

#endif