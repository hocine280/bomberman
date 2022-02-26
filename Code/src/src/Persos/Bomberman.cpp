#include "../../include/Persos/Bomberman.h"

#include "../../include/Persos/Personnage.h"
#include "../../include/Map/Position.h"

Bomberman::Bomberman(int x, int y, int life, int speed, int bombMax, int nbBomb): Personnage(x, y, life, speed), m_bombMax(bombMax), m_nbBomb(nbBomb)
{
	if(bombMax < 1)
	{
		bombMax = 5;
	}

	if(nbBomb < 0)
	{
		nbBomb = 2;
	}
}

int Bomberman::getBombMax() const
{
	return m_bombMax;
}

int Bomberman::getNbBomb() const
{
	return m_nbBomb;
}

void Bomberman::addBomb()
{

}

void Bomberman::dropBomb()
{

}