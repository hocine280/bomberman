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
		bool validateMove = false;
		Position testPosition = m_position;
		direction = utilities::EDirection::NONE;

		testPosition.setY(testPosition.getY()-m_speed);
		if(testPosition.getY() >= 0)
		{
			direction = utilities::EDirection::LEFT;
			move(direction);
			validateMove = true;
		}
		
		testPosition.setY(testPosition.getY()+2*m_speed);
		if(!validateMove && testPosition.getY() < map[testPosition.getX()].size())
		{
			direction = utilities::EDirection::RIGHT;
			move(direction);
			validateMove = true;
		}

		testPosition.setX(testPosition.getX()-m_speed);
		testPosition.setY(testPosition.getY()-m_speed);
		if(!validateMove && testPosition.getX() >= 0)
		{
			direction = utilities::EDirection::TOP;
			move(direction);
			validateMove = true;
		}

		testPosition.setX(testPosition.getX()+2*m_speed);
		if(!validateMove && testPosition.getX() < map.size())
		{
			direction = utilities::EDirection::BOTTOM;
			move(direction);
			validateMove = true;
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