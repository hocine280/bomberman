#ifndef __BOMBERMAN__
#define __BOMBERMAN__

#include "Personnage.h"
#include "../Map/Position.h"

class Bomberman: public Personnage
{
	private:
		int m_bombMax, m_nbBomb;

	public:
		Bomberman(int x=0, int y=0, int life=3, int speed=1, int bombMax=5, int nbBomb=2);
		~Bomberman();

		int getBombMax() const;
		int getNbBomb() const;
		void addBomb(int);
		void dropBomb();
		void show() const override;
		void showPosition() const;
};

#endif