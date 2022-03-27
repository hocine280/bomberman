#ifndef __ENNEMY__
#define __ENNEMY__

#include "../Map/Position.h"
#include "../Map/Tile.h"

#include "Personnage.h"

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

		virtual utilities::EDirection play(std::vector<std::vector<Tile*>> map);
};

#endif