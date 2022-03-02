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
			m_position.setX(m_position.getX()-1);
			break;

		case utilities::EDirection::BOTTOM :
			m_position.setX(m_position.getX()+1);
			break;

		case utilities::EDirection::LEFT :
			m_position.setY(m_position.getY()-1);
			break;

		case utilities::EDirection::RIGHT :
			m_position.setY(m_position.getY()+1);
			break;

		default:
			break;
	}
}

void Arrow::show() const override
{
	switch(m_direction)
	{
		case utilities::EDirection::TOP :
			
			break;

		case utilities::EDirection::BOTTOM :
			
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