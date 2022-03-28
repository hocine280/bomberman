#ifndef __ARROW__
#define __ARROW__

#include "Item.h"
#include "../engine/utilities.h"

class Arrow: public Item
{
	private:
		int m_speed;
		int m_damage;
		utilities::EDirection m_direction;

	public:
		Arrow(int x = 0, int y = 0, int speed = 1, int damage = 1, utilities::EDirection direction = utilities::EDirection::NONE);

		void move();
		virtual void showTop() const override;
		virtual void showMiddle() const override;
		virtual void showBottom() const override;

		virtual void play() override;
};

#endif