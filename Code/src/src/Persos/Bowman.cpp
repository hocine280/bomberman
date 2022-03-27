#include "../../include/Persos/Bowman.h"

#include <iostream>

Bowman::Bowman(int x, int y, int life, int speed, int damage, int still): Ennemy(x, y, life, speed, damage, still){}

Bowman::~Bowman()
{

}

void Bowman::show() const
{
	std::cout << " B ";
}

Arrow Bowman::shootArrow(utilities::EDirection) const
{
	return Arrow();
}

utilities::EDirection Bowman::shootPlayer() const
{
	return utilities::EDirection::NONE;
}