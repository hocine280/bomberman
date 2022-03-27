#include "../../include/Persos/Ennemy.h"

Ennemy::Ennemy(int x, int y, int life, int speed, int damage, int still): Personnage(x, y, life, speed), m_damage(damage), m_still(still)
{
	if(damage < 1)
	{
		damage = 1;
	}
}

Ennemy::~Ennemy()
{
	
}

int Ennemy::getDamage() const
{
	return m_damage;
}

void Ennemy::setDamage(int damage)
{
	if(damage > 0)
	{
		m_damage = damage;
	}
}
/*
void Ennemy::play(Map map)
{
	if(m_still > 0)
	{
		m_still--;
		return;
	}

	Position testPosition = getPosition();

	testPosition.setX(testPosition.getX()-m_speed);
	if(map.tileIsFree(testPosition))
	{
		move(utilities::EDirection::LEFT);
	}
	
	testPosition.setX(testPosition.getX()+2*m_speed);
	if(map.tileIsFree(testPosition))
	{
		move(utilities::EDirection::RIGHT);
	}

	testPosition.setX(testPosition.getX()-m_speed);
	testPosition.setY(testPosition.getY()-m_speed);
	if(map.tileIsFree(testPosition))
	{
		move(utilities::EDirection::TOP);
	}

	testPosition.setY(testPosition.getY()+2*speed);
	if(map.tileIsFree(testPosition))
	{
		move(utilities::EDirection::BOTTOM);
	}
}*/