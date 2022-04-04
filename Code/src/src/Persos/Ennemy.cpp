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

utilities::EDirection Ennemy::play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items)
{
	if(m_still > 0)
	{
		m_still--;
		return utilities::EDirection::NONE;
	}

	utilities::EDirection moveDirection = utilities::EDirection::NONE;
	bool validateMove = false;
	Position testPosition = m_position;

	int moveX =  player->getPosition().getX() - testPosition.getX();
	int moveY = player->getPosition().getY() - testPosition.getY();
	int i = 0;

	if(moveX < 0)
	{
		moveDirection = utilities::EDirection::TOP;
	}
	else if(moveX > 0)
	{
		moveDirection = utilities::EDirection::BOTTOM;
	}
	else if(moveY < 0)
	{
		moveDirection = utilities::EDirection::LEFT;
	}
	else if(moveY > 0)
	{
		moveDirection = utilities::EDirection::RIGHT;
	}

	while(!validateMove)
	{
		switch (moveDirection)
		{
			case utilities::EDirection::TOP:
				testPosition.setX(testPosition.getX()-m_speed);
				if(testPosition.getX() >= 0 && map[testPosition.getX()][testPosition.getY()]->getBeCrossed())
				{
					validateMove = true;
				}
				else if(testPosition == player->getPosition() && !validateMove)
				{
					player->receiveDamage(m_damage);
					m_still = 3;
					validateMove = true;
				}
				break;

			case utilities::EDirection::BOTTOM:
				testPosition.setX(testPosition.getX()+m_speed);
				if(testPosition.getX() < map.size() && map[testPosition.getX()][testPosition.getY()]->getBeCrossed())
				{
					validateMove = true;
				}
				else if(testPosition == player->getPosition() && !validateMove)
				{
					player->receiveDamage(m_damage);
					m_still = 3;
					validateMove = true;
				}
				break;

			case utilities::EDirection::LEFT:
				testPosition.setY(testPosition.getY()-m_speed);
				if(testPosition.getY() >= 0 &&  map[testPosition.getX()][testPosition.getY()]->getBeCrossed())
				{
					validateMove = true;
				}
				else if(testPosition == player->getPosition())
				{
					player->receiveDamage(m_damage);
					m_still = 3;
					validateMove = true;
				}
				break;

			case utilities::EDirection::RIGHT:
				testPosition.setY(testPosition.getY()+m_speed);
				if(testPosition.getY() < map[testPosition.getX()].size() && map[testPosition.getX()][testPosition.getY()]->getBeCrossed())
				{
					validateMove = true;
				}
				else if(testPosition == player->getPosition() && !validateMove)
				{
					player->receiveDamage(m_damage);
					m_still = 3;
					validateMove = true;
				}
				break;
			
			default:
				validateMove = true;
				break;
		}

		if(!validateMove)
		{
			testPosition = m_position;
			switch (i)
			{
				case 0:
					moveDirection = utilities::EDirection::LEFT;
					i++;
					break;

				case 1:
					moveDirection = utilities::EDirection::RIGHT;
					i++;
					break;

				case 2:
					moveDirection = utilities::EDirection::TOP;
					i++;
					break;

				case 3:
					moveDirection = utilities::EDirection::BOTTOM;
					i++;
					break;
				
				default:
					moveDirection = utilities::EDirection::NONE;
					break;
			}
		}
	}

	if(moveDirection != utilities::EDirection::NONE)
	{
		move(moveDirection);
	}

	return moveDirection;
}