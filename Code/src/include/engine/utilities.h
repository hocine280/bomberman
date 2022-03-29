#ifndef __UTILITIES__
#define __UTILITIES__

namespace utilities
{
	typedef enum
	{
		TOP,
		BOTTOM,
		LEFT,
		RIGHT,
		NONE
	}EDirection;

	typedef enum
	{
		LINE,
		COLUMN,
		CENTER,
		NOEXPLOSION
	}EBombExplosionDirection;
}

#endif