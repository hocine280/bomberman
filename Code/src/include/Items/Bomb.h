#ifndef __BOMB__
#define __BOMB__

#include "Item.h"

class Bomb
{
	private:
		double m_scope;
		int m_turnBeforeExplosion
		
	public:
		int static power = 1;

		Bomb(int x = 0, int y = 0, double scope, int turnBeforeExplosion);
		~Bomb();

		double getScope() const;
		int getTurnBeforeExplosion() const;

		void decreaseTurnBeforeExplosion();

		void showTop() const override;
		void showMiddle() const override;
		void showBottom() const override;
};

#endif