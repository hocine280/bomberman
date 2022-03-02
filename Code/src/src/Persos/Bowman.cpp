#include "../../include/Persos/Bowman.h"

#include <iostream>

Bowman::Bowman(int x, int y, int life, int speed, int damage): Ennemy(x, y, life, speed, damage){}

Bowman::~Bowman()
{

}

void Bowman::show() const
{
	std::cout << "B";
}

Arrow Bowman::shootArrow(utilities::EDirection) const
{

}

utilities::EDirection Bowman::shootPlayer() const
{
	
}