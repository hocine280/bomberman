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

bool Personnage::move(utilities::EDirection direction)
{
	bool back = 1;

	switch(direction)
	{
		case utilities::EDirection::TOP :
			m_position.setX(m_position.getX()+1);
			break;

		case utilities::EDirection::BOTTOM :
			m_position.setX(m_position.getX()-1);
			break;

		case utilities::EDirection::LEFT :
			m_position.setY(m_position.getY()-1);
			break;

		case utilities::EDirection::RIGHT :
			m_position.setY(m_position.getY()+1);
			break;

		default:
			back = 0;
			break;
	}

	return back;
}