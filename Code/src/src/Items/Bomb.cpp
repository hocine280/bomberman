#include "../../include/Items/Bomb.h"

#include <iostream>

int Bomb::power = 1;
double Bomb::scope = 1.5;

Bomb::Bomb(int x, int y, int turnBeforeExplosion): Item(x, y), m_turnBeforeExplosion(turnBeforeExplosion)
{

}

Bomb::~Bomb()
{
	
}

int Bomb::getTurnBeforeExplosion() const
{
	return m_turnBeforeExplosion;
}

void Bomb::decreaseTurnBeforeExplosion()
{
	if(m_turnBeforeExplosion > 0)
	{
		m_turnBeforeExplosion --;
	}
}

void Bomb::showTop() const
{
	std:: cout << "   ";
}

void Bomb::showMiddle() const
{
	std::cout << " O ";
}

void Bomb::showBottom() const
{
	std::cout << "   ";
}