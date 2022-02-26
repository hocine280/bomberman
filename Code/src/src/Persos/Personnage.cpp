#include "../../include/Persos/Personnage.h"

Personnage::Personnage(int x, int y, int life, int speed): m_position(x, y), m_life(life), m_speed(speed)
{
	if(life < 1)
	{
		life = 3;
	}
	
	if(speed < 1)
	{
		speed = 1;
	}
}

virtual Personnage::~Personnage()
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