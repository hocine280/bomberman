#include "../../include/Persos/Ghost.h"

#include <iostream>

Ghost::Ghost(int x, int y, int life, int speed, int damage, int still): Ennemy(x, y , life, speed, damage, still){}

Ghost::~Ghost()
{

}

utilities::EDirection Ghost::play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items)
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
				if(testPosition == player->getPosition() && !validateMove)
				{
					player->receiveDamage(m_damage);
					m_still = 3;
					validateMove = true;
				}
				else if(testPosition.getX() >= 0)
				{
					validateMove = true;
				}
				break;

			case utilities::EDirection::BOTTOM:
				testPosition.setX(testPosition.getX()+m_speed);
				if(testPosition == player->getPosition() && !validateMove)
				{
					player->receiveDamage(m_damage);
					m_still = 3;
					validateMove = true;
				}
				else if(testPosition.getX() < map.size())
				{
					validateMove = true;
				}
				break;

			case utilities::EDirection::LEFT:
				testPosition.setY(testPosition.getY()-m_speed);
				if(testPosition == player->getPosition() && !validateMove)
				{
					player->receiveDamage(m_damage);
					m_still = 3;
					validateMove = true;
				}
				else if(testPosition.getY() >= 0)
				{
					validateMove = true;
				}
				break;

			case utilities::EDirection::RIGHT:
				testPosition.setY(testPosition.getY()+m_speed);
				if(testPosition == player->getPosition() && !validateMove)
				{
					player->receiveDamage(m_damage);
					m_still = 3;
					validateMove = true;
				}
				else if(testPosition.getY() < map[testPosition.getX()].size())
				{
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

	return utilities::EDirection::NONE;
}

void Ghost::show() const
{
	std::cout << " G ";
}