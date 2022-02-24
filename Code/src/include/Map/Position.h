#ifndef __POSITION__
#define __POSITION__

class Position
{
	private:
		int m_x, m_y;
		
	public:
		Position();

		int getX() const;
		int getY() const;
		void setX(int);
		void setY(int);
};

#endif