#include "../../include/Persos/Personnage.h"

Personnage::Personnage(Position position, int life, int speed): m_position(position), m_life(life), m_speed(speed)
{
	life > 0;
	speed > 0;
}

Personnage::~Personnage()
{
	
}

Position Personnage::getPosition() const
{
	return m_position;
}

int Personnage::getLife() const
{
	return m_life;
}

int Personnage::getSpeed() const
{
	return m_speed;
}