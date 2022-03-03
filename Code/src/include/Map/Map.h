#ifndef __MAP__
#define __MAP__

#include <vector>

class Map
{
	private:
		int m_nbColumn = 8;
		int m_nbLine = 8;
		Tile m_target;
		Bomberman m_player;
		Tile m_mapTile[8][8];
		std::vector <Ennemy> m_listEnnemy;
		std::vector <Item> m_listItems;

	public:
		Map();
		~Map();

		Tile getTarget() const;
		int getNbColumn() const;
		int getNbLine() const;
		Bomberman getPlayer() const;
		void showMap() const;
};

#endif