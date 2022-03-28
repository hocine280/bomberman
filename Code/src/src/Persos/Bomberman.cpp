#include "../../include/Persos/Bomberman.h"

#include "../../include/Persos/Personnage.h"
#include "../../include/Map/Position.h"

#include <iostream>

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

Bomberman::~Bomberman()
{

}

int Bomberman::getBombMax() const
{
	return m_bombMax;
}

int Bomberman::getNbBomb() const
{
	return m_nbBomb;
}

void Bomberman::addLife(int life)
{
	if(life < 0)
	{
		life = -life;
	}
	m_life += life;
}

void Bomberman::addBomb(int nbBomb)
{
	if(nbBomb > 0)
	{
		m_nbBomb += nbBomb;
	}
}

void Bomberman::addSpeed(int speed)
{
	if(speed < 0)
	{
		speed = -speed;
	}
	m_speed += speed;
}

void Bomberman::dropBomb()
{
	m_nbBomb--;
}

void Bomberman::show() const
{
	std::cout << " P ";
}