#include <iostream>

#include "src/include/engine/SystemGame.h"

int main(void)
{
	std::cout << "============= Test du Bomberman ===================" << std::endl << std::endl;

	SystemGame SG;

	SG.showMap();

	SG.playTurn();
	SG.playTurn();

	std::cout << "============= Fin du test ===================" << std::endl << std::endl;
	return 0;
}