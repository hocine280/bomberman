#include "../../include/Persos/Ennemy.h"
#include <iostream>

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

utilities::EDirection Ennemy::play(std::vector<std::vector<Tile*>> map, Bomberman *player)
{
	if(m_still > 0)
	{
		m_still--;
		return utilities::EDirection::NONE;
	}

	utilities::EDirection moveDirection = utilities::EDirection::NONE;
	bool validateMove = false;
	Position testPosition = getPosition();

	testPosition.setY(testPosition.getY()-m_speed);
	if(testPosition.getY() >= 0 &&  map[testPosition.getX()][testPosition.getY()]->getBeCrossed())
	{
		moveDirection = utilities::EDirection::LEFT;
		validateMove = true;
	}
	else if(testPosition == player->getPosition())
	{
		player->receiveDamage(m_damage);
		m_still = 3;
		validateMove = true;
	}
	
	testPosition.setY(testPosition.getY()+2*m_speed);
	if(!validateMove && testPosition.getY() < map[testPosition.getX()].size() && map[testPosition.getX()][testPosition.getY()]->getBeCrossed())
	{
		moveDirection = utilities::EDirection::RIGHT;
		validateMove = true;
	}
	else if(testPosition == player->getPosition() && !validateMove)
	{
		player->receiveDamage(m_damage);
		m_still = 3;
		validateMove = true;
	}

	testPosition.setX(testPosition.getX()-m_speed);
	testPosition.setY(testPosition.getY()-m_speed);
	if(!validateMove && testPosition.getX() >= 0 && map[testPosition.getX()][testPosition.getY()]->getBeCrossed())
	{
		moveDirection = utilities::EDirection::TOP;
		validateMove = true;
	}
	else if(testPosition == player->getPosition() && !validateMove)
	{
		player->receiveDamage(m_damage);
		m_still = 3;
		validateMove = true;
	}

	testPosition.setX(testPosition.getX()+2*m_speed);
	if(!validateMove && testPosition.getX() < map.size() && map[testPosition.getX()][testPosition.getY()]->getBeCrossed())
	{
		moveDirection = utilities::EDirection::BOTTOM;
		validateMove = true;
	}
	else if(testPosition == player->getPosition() && !validateMove)
	{
		player->receiveDamage(m_damage);
		m_still = 3;
		validateMove = true;
	}

	if(validateMove)
	{
		move(moveDirection);
	}

	return moveDirection;
}