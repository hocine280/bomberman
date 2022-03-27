#include "../../include/Persos/Monster.h"

#include <iostream>

Monster::Monster(int x, int y, int life, int speed, int damage, int still): Ennemy(x, y, life, speed, damage, still){}

Monster::~Monster()
{

}

void Monster::show() const
{
	std::cout << " M ";
}