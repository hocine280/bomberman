#include "../../include/Items/Arrow.h"

#include <iostream>

Arrow::Arrow(int x, int y, int speed, int damage, utilities::EDirection direction): Item(x, y), m_speed(speed), m_damage(damage), m_direction(direction)
{
	if(speed < 1)
	{
		speed = 1;
	}

	if(damage < 1)
	{
		damage = 1;
	}
}

void Arrow::move()
{
	switch(m_direction)
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
			break;
	}
}

bool Arrow::play(std::vector<std::vector<Tile*>> map, Bomberman *player, std::vector<Item*> *items)
{
	bool remove = false;
	Arrow test = *this;
	test.move();
	if(test.getPosition() == player->getPosition())
	{
		player->receiveDamage(m_damage);
		remove = true;
	}
	else if(test.getPosition().getX() < 0 || test.getPosition().getX() >= map.size() || test.getPosition().getY() < 0 || test.getPosition().getY() >= map[test.getPosition().getX()].size())
	{
		remove = true;
	}
	else if(!map[test.getPosition().getX()][test.getPosition().getY()]->getBeCrossed())
	{
		remove = true;
	}
	else
	{
		move();
	}

	return remove;
}

void Arrow::showTop() const
{
	if(m_direction == utilities::EDirection::TOP)
	{
		std::cout << " A ";
	}
	else
	{
		std::cout << "   ";
	}
}

void Arrow::showMiddle() const
{
	switch(m_direction)
	{
		case utilities::EDirection::TOP :
			std::cout << " | ";
			break;

		case utilities::EDirection::BOTTOM :
			std::cout << " | ";
			break;

		case utilities::EDirection::LEFT :
			std::cout << "<--";
			break;

		case utilities::EDirection::RIGHT :
			std::cout << "-->";
			break;

		default:
			break;
	}
}

void Arrow::showBottom() const
{
	if(m_direction == utilities::EDirection::BOTTOM)
	{
		std::cout << " V ";
	}
	else
	{
		std::cout << "   ";
	}
}