#ifndef __SPEEDUP__
#define __SPEEDUP__

#include "Item.h"
#include "../Persos/Bomberman.h"

class SpeedUp: public Item
{
	private:
		int m_speed;
		
	public:
		SpeedUp(int x = 0, int y = 0, int speed = 1);
		~SpeedUp();

		void increaseSpeed(Bomberman* b);

		void showTop() const override;
		void showMiddle() const override;
		void showBottom() const override;

		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
};

#endif