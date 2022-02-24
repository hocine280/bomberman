#ifndef __SYSTEMGAME__
#define __SYSTEMGAME__

class SystemGame
{
	private:
		Bomberman m_player;
		Map m_map;

		void turnPlayer();
		void turnBomb();
		void turnEnnemy();
		
	public:
		System();

		void refreshMap();
		void showGame();
		void playTurn();
};

#endif