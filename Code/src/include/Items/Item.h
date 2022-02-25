#ifndef __ITEM__
#define __ITEM__

#include "../Map/Position.h"

class Item
{
	protected:
		Position m_position;
		
	public:
		Item(Position position = Position position());
		~Item();

		Position getPosition() const;
		void show() const;
};


#endif