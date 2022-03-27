#include "../../include/Persos/Ghost.h"

#include <iostream>

Ghost::Ghost(int x, int y, int life, int speed, int damage, int still): Ennemy(x, y , life, speed, damage, still){}

Ghost::~Ghost()
{

}

void Ghost::show() const
{
	std::cout << " G ";
}