#include "../../include/Map/Map.h"
#include "../../include/Map/Wall.h"

#include <iostream>

int main(void)
{
	int nbColumn, nbLine;

	std::cout << "Saisir le nombre de ligne de la map :";
	std::cin >> nbLine;
	std::cout << "Saisir le nombre de colonne de la map :";
	std::cin >> nbColumn;

	Map map(nbLine, nbColumn);

	std::cout << "Map line: " << map.getNbLine() << " | column: " << map.getNbColumn() << std::endl;

	std::cout << std::endl << std::endl;

	map.showMap();

	return 0;
}