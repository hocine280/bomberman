#ifndef __ITEM__
#define __ITEM__

#include "../Map/Position.h"

class Item
{
	protected:
		Position m_position;
		
	public:
		Item(int x = 0, int y = 0);
		~Item();

		Position getPosition() const;
		virtual void showTop() const = 0;
		virtual void showMiddle() const = 0;
		virtual void showBottom() const = 0;
};


#endif