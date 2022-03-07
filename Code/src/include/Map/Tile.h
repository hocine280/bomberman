#ifndef __TILE__
#define __TILE__

#include "Position.h"

class Tile
{
	private:
		Position m_position;
		bool m_beCrossed;

	public:
		Tile(int x = 0; int y = 0, bool beCrossed = true);
		~Tile();

		Position getPosition() const;
		bool getBeCrossed() const;
};

#endif