#include "../../include/Persos/Ennemy.h"

#include "../../include/Persos/Personnage.h"
#include "../../include/Map/Position.h"

Ennemy::Ennemy(int x, int y, int life, int speed, int damage): Personnage(x, y, life, speed), m_damage(damage)
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