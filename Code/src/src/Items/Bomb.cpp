#include "../../include/Items/Bomb.h"

Bomb::Bomb(int x, int y, double scope, int turnBeforeExplosion): Item(x, y), m_scope(scope), m_turnBeforeExplosion(turnBeforeExplosion)
{

}

double Bomb::getScope() const
{
	return m_scope;
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