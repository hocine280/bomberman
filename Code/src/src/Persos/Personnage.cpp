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

void Personnage::receiveDamage(int damage)
{
	if(damage > 0)
	{
		m_life -= damage;
	}
}

bool Personnage::move(utilities::EDirection direction)
{
	bool back = true;

	switch(direction)
	{
		case utilities::EDirection::TOP :
			m_position.setX(m_position.getX()-m_speed);
			break;

		case utilities::EDirection::BOTTOM :
			m_position.setX(m_position.getX()+m_speed);
			break;

		case utilities::EDirection::LEFT :
			m_position.setY(m_position.getY()-m_speed);
			break;

		case utilities::EDirection::RIGHT :
			m_position.setY(m_position.getY()+m_speed);
			break;

		default:
			back = false;
			break;
	}

	return back;
}