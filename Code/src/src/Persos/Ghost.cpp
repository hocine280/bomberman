#include "../../include/Persos/Ghost.h"

#include <iostream>

Ghost::Ghost(int x, int y, int life, int speed, int damage): Ennemy(x, y , life, speed, damage){}

Ghost::~Ghost()
{

}

void Ghost::show() const override
{
	std::cout << "G";
}