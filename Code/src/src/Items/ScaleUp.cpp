#include "../../include/Items/ScaleUp.h"
#include "../../include/Items/Bomb.h"

#include <iostream>

ScaleUp::ScaleUp(int x, int y, double scope): Item(x, y), m_scope(scope)
{

}

ScaleUp::~ScaleUp()
{
	
}

void ScaleUp::increaseScope()
{
	Bomb::scope += m_scope;
}

void ScaleUp::showTop() const
{
	std::cout << "   ";
}

void ScaleUp::showMiddle() const
{
	std::cout << " SC";
}

void ScaleUp::showBottom() const
{
	std::cout << "   ";
}