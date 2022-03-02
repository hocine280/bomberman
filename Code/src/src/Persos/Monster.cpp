#include "../../include/Persos/Monster.h"

#include <iostream>

Monster::Monster(int x, int y, int life, int speed, int damage): Ennemy(x, y, life, speed, damage){}

Monster::~Monster()
{

}

void Monster::show() const
{
	std::cout << "M";
}