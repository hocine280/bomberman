#include "../../include/Persos/Bowman.h"

#include <iostream>

Bowman::Bowman(int x, int y, int life, int speed, int damage, int still): Ennemy(x, y, life, speed, damage, still){}

Bowman::~Bowman()
{

}

void Bowman::show() const
{
	std::cout << " B ";
}

utilities::EDirection Bowman::play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items)
{
	if(m_still > 0)
	{
		m_still--;
		return utilities::EDirection::NONE;
	}

	utilities::EDirection direction;
	direction = shootPlayer(player);
	if(direction != utilities::EDirection::NONE)
	{
		Arrow a = shootArrow(direction);
		items->push_back(new Arrow(a));
		direction = utilities::EDirection::NONE;
		m_still = 2;
	}
	else
	{
		direction = utilities::EDirection::NONE;
		bool validateMove = false;
		Position testPosition = m_position;

		int moveX =  player->getPosition().getX() - testPosition.getX();
		int moveY = player->getPosition().getY() - testPosition.getY();
		int i = 0;

		if(moveX < 0)
		{
			direction = utilities::EDirection::TOP;
		}
		else if(moveX > 0)
		{
			direction = utilities::EDirection::BOTTOM;
		}
		else if(moveY < 0)
		{
			direction = utilities::EDirection::LEFT;
		}
		else if(moveY > 0)
		{
			direction = utilities::EDirection::RIGHT;
		}

		while(!validateMove)
		{
			switch (direction)
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
						direction = utilities::EDirection::LEFT;
						i++;
						break;

					case 1:
						direction = utilities::EDirection::RIGHT;
						i++;
						break;

					case 2:
						direction = utilities::EDirection::TOP;
						i++;
						break;

					case 3:
						direction = utilities::EDirection::BOTTOM;
						i++;
						break;
					
					default:
						direction = utilities::EDirection::NONE;
						break;
				}
			}
		}

		if(direction != utilities::EDirection::NONE)
		{
			move(direction);
		}
	}

	return direction;
}

Arrow Bowman::shootArrow(utilities::EDirection direction) const
{
	Arrow a;
	switch (direction)
	{
		case utilities::EDirection::LEFT :
			a = Arrow(m_position.getX(), m_position.getY()-1, 1, 1, direction);
			break;

		case utilities::EDirection::RIGHT :
			a = Arrow(m_position.getX(), m_position.getY()+1, 1, 1, direction);
			break;

		case utilities::EDirection::TOP :
			a = Arrow(m_position.getX()-1, m_position.getY(), 1, 1, direction);
			break;

		case utilities::EDirection::BOTTOM :
			a = Arrow(m_position.getX()+1, m_position.getY(), 1, 1, direction);
			break;
		
		default:
			break;
	}

	return a;
}

utilities::EDirection Bowman::shootPlayer(Bomberman *player) const
{
	bool sameLine = false;
	bool sameColumn = false;
	Position positionPlayer = player->getPosition();
	utilities::EDirection direction = utilities::EDirection::NONE;
	
	if(positionPlayer.getX() == m_position.getX())
	{
		sameLine = true;
	}
	else if(positionPlayer.getY() == m_position.getY())
	{
		sameColumn = true;
	}

	if(sameLine)
	{
		if(positionPlayer.getY() < m_position.getY())
		{
			direction = utilities::EDirection::LEFT;
		}
		else
		{
			direction = utilities::EDirection::RIGHT;
		}
	}
	else if(sameColumn)
	{
		if(positionPlayer.getX() < m_position.getX())
		{
			direction = utilities::EDirection::TOP;
		}
		else
		{
			direction = utilities::EDirection::BOTTOM;
		}
	}

	return direction;
}