#ifndef __WALL__
#define __WALL__

#include "Tile.h"

class Wall : public Tile
{
	private:
		bool m_destructible;
		int m_nbNecessaryBomb;

	public:
		Wall(int x = 0, int y = 0, bool beCrossed, bool destructible, int nbNecessaryBomb);
		~Wall();

		bool getDestructible() const;
		int getNbNecessaryBomb() const;

		void weaken();
};

#endif