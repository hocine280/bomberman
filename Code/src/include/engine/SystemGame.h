#ifndef __SYSTEMGAME__
#define __SYSTEMGAME__

#include "../Persos/Bomberman.h"
#include "../Map/Map.h"

class SystemGame
{
	private:
		Map m_map;

		void turnPlayer();
		void turnBomb();
		void turnEnnemy();
		
	public:
		SystemGame(int level = 1);

		void showMap();
		void playTurn();
		bool endGame();
};

#endif