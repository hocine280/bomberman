#ifndef __MAP__
#define __MAP__

#include <vector>

class Map
{
	private:
		int m_nbColumn;
		int m_nbLine;
		Tile m_target;
		Bomberman m_player;
		Tile** m_mapTile;
		std::vector <Ennemy> m_listEnnemy;
		std::vector <Item> m_listItems;

	public:
		Map(int nbLine = 8, int nbColumn = 8);
		~Map();

		Tile getTarget() const;
		int getNbColumn() const;
		int getNbLine() const;
		Bomberman getPlayer() const;
		void loadMap();
		void showMap() const;
};

#endif