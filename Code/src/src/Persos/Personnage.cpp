#include "../../include/Persos/Personnage.h"

Personnage::Personnage(Position position, int life, int speed): m_position(position), m_life(life), m_speed(speed){};

Position Personnage::getPosition() const
{
	return m_position;
}