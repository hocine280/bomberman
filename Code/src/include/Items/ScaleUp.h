#ifndef __SCALEUP__
#define __SCALEUP__

#include "Item.h"

class ScaleUp: public Item
{
	private:
		double m_scope;
		
	public:
		ScaleUp(int x = 0, int y = 0, double scope = 0.5);
		~ScaleUp();

		void increaseScope();

		void showTop() const override;
		void showMiddle() const override;
		void showBottom() const override;
};

#endif