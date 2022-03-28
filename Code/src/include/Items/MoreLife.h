#ifndef __MORELIFE__
#define __MORELIFE__

#include "Item.h"
#include "../Persos/Bomberman.h"

class MoreLife: public Item
{
	private:
		int m_lifePoint;

	public:
		MoreLife(int x = 0, int y = 0, int lifePoint = 1);
		~MoreLife();

		void increaseLife(Bomberman* b);

		void showTop() const override;
		void showMiddle() const override;
		void showBottom() const override;

		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
};

#endif