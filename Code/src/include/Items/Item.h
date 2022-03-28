#ifndef __ITEM__
#define __ITEM__

#include "../Map/Position.h"
#include "../Map/Tile.h"

#include "../Persos/Bomberman.h"

#include <vector>

class Item
{
	protected:
		Position m_position;
		
	public:
		Item(int x = 0, int y = 0);
		~Item();

		Position getPosition() const;
		virtual void showTop() const = 0;
		virtual void showMiddle() const = 0;
		virtual void showBottom() const = 0;

		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) = 0;
};


#endif