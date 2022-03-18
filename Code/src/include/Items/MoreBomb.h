#ifndef __MOREBOMB__
#define __MOREBOMB__

#include "Item.h"
#include "../Persos/Bomberman.h"

class MoreBomb: public Item
{
	private:
		int m_nbBomb;
		
	public:
		MoreBomb(int x = 0, int y = 0, int nbBomb = 1);
		~MoreBomb();

		void increaseNbBomb(Bomberman* b);

		void showTop() const override;
		void showMiddle() const override;
		void showBottom() const override;
};

#endif