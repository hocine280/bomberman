#ifndef __POWERUP__
#define __POWERUP__

#include "Item.h"
#include "../Persos/Bomberman.h"

class PowerUp
{
	private:
		int m_powerPoint;
		
	public:
		PowerUp(int x = 0, int y = 0, int powerPoint = 1);
		~PowerUp();

		void increasePower();
		void showTop() const override;
		void showMiddle() const override;
		void showBottom() const override;
};

#endif