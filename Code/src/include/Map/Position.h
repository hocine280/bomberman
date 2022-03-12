#ifndef __POSITION__
#define __POSITION__

class Position
{
	private:
		int m_x, m_y;
		
	public:
		Position(int x = 0, int y = 0);

		int getX() const;
		int getY() const;
		void setX(int);
		void setY(int);

		bool operator==(const Position& other);
		bool operator!=(const Position& other);
};

#endif