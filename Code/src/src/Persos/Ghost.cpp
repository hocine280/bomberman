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

	bool validateMove = false;
	Position testPosition = m_position;

	testPosition.setY(testPosition.getY()-m_speed);
	if(testPosition == player->getPosition())
	{
		player->receiveDamage(m_damage);
		m_still = 3;
		move(utilities::EDirection::LEFT);
		validateMove = true;
	}
	else if(testPosition.getY() >= 0)
	{
		move(utilities::EDirection::LEFT);
		validateMove = true;
	}
	
	testPosition.setY(testPosition.getY()+2*m_speed);
	if(!validateMove && testPosition == player->getPosition())
	{
		player->receiveDamage(m_damage);
		m_still = 3;
		validateMove = true;
	}
	else if(!validateMove && testPosition.getY() < map[testPosition.getX()].size())
	{
		move(utilities::EDirection::RIGHT);
		validateMove = true;
	}

	testPosition.setX(testPosition.getX()-m_speed);
	testPosition.setY(testPosition.getY()-m_speed);
	if(!validateMove && testPosition == player->getPosition())
	{
		player->receiveDamage(m_damage);
		m_still = 3;
		validateMove = true;
	}
	else if(!validateMove && testPosition.getX() >= 0)
	{
		move(utilities::EDirection::TOP);
		validateMove = true;
	}

	testPosition.setX(testPosition.getX()+2*m_speed);
	if(!validateMove && testPosition == player->getPosition())
	{
		player->receiveDamage(m_damage);
		m_still = 3;
		validateMove = true;
	}
	else if(!validateMove && testPosition.getX() < map.size())
	{
		move(utilities::EDirection::BOTTOM);
		validateMove = true;
	}

	return utilities::EDirection::NONE;
}

void Ghost::show() const
{
	std::cout << " G ";
}