#include "../../include/Items/Item.h"
#include "../../include/Items/Arrow.h"
#include "../../include/Items/Bomb.h"
#include "../../include/Items/MoreBomb.h"
#include "../../include/Items/MoreLife.h"
#include "../../include/Items/PowerUp.h"
#include "../../include/Items/ScaleUp.h"
#include "../../include/Items/SpeedUp.h"

#include "../../include/Map/Position.h"

#include "../../include/engine/utilities.h"

#include <iostream>
#include <vector>

int main(void)
{
	std::vector<Item*> itemsVector;

	Arrow a(0, 0, 1, 2, utilities::EDirection::LEFT);
	Bomb b;
	MoreBomb mb;
	MoreLife ml;
	PowerUp pu;
	ScaleUp su;
	SpeedUp sp;

	itemsVector.push_back(&a);
	itemsVector.push_back(&b);
	itemsVector.push_back(&mb);
	itemsVector.push_back(&ml);
	itemsVector.push_back(&pu);
	itemsVector.push_back(&su);
	itemsVector.push_back(&sp);

	std::cout << "Affichage flèche : "; itemsVector[0]->showMiddle(); std::cout << std::endl;
	std::cout << "Affichage Bomb : "; itemsVector[1]->showMiddle(); std::cout << std::endl;
	std::cout << "Affichage MoreBomb : "; itemsVector[2]->showMiddle(); std::cout << std::endl;
	std::cout << "Affichage MoreLife : "; itemsVector[3]->showMiddle(); std::cout << std::endl;
	std::cout << "Affichage PowerUp : "; itemsVector[4]->showMiddle(); std::cout << std::endl;
	std::cout << "Affichage ScaleUp : "; itemsVector[5]->showMiddle(); std::cout << std::endl;
	std::cout << "Affichage SpeedUp : "; itemsVector[6]->showMiddle(); std::cout << std::endl;

	return 0;
}