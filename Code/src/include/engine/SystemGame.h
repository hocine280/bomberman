#ifndef __SYSTEMGAME__
#define __SYSTEMGAME__

#include "../Persos/Bomberman.h"
#include "../Map/Map.h"

class SystemGame
{
	private:
		Bomberman m_player;
		Map m_map;

		void turnPlayer();
		void turnBomb();
		void turnEnnemy();
		
	public:
		SystemGame();

		void showMap();
		void playTurn();
};

#endif