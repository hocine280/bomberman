#ifndef __BOMB__
#define __BOMB__

#include "Item.h"

class Bomb: public Item
{
	private:
		int m_turnBeforeExplosion;
		
	public:
		static int power;
		static double scope;

		Bomb(int x = 0, int y = 0, int turnBeforeExplosion = 3);
		~Bomb();

		double getScope() const;
		int getTurnBeforeExplosion() const;

		void decreaseTurnBeforeExplosion();

		void showTop() const override;
		void showMiddle() const override;
		void showBottom() const override;

		virtual bool play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items) override;
};

#endif