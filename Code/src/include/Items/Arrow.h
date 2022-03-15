#ifndef __ARROW__
#define __ARROW__

#include "../engine/utilities.h"

class Arrow
{
	private:
		int m_speed;
		int m_damage;
		utilities::EDirection m_direction;

	public:
		Arrow(int x = 0, int x = 0, int speed = 1, int damage = 1, utilities::EDirection direction = utilities::EDirection::NONE);

		void move();
		void showTop() const override;
		void showMiddle() const override;
		void showBottom() const override;
};

#endif