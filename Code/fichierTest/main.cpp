#include <iostream>

#include "../../include/Persos/Personnage.h"
#include "../../include/Persos/Bomberman.h"
#include "../../include/engine/utilities.h"

int main()
{
	Bomberman b;
	int saisie;

	b.show();
	std::cout << std::endl;

	b.showPosition();

	if(b.move(utilities::EDirection::TOP))
	{
		b.showPosition();
	}
	else
	{
		b.show();
		std::cout << std::endl;
	}

	do
	{
		std::cout << "Que souhaitez-vous faire ?" << std::endl << "0 - Exit" << std::endl << "1 - Avancer top" << std::endl << "2 - Avancer bottom" << std::endl;

		std::cin >> saisie;

		switch(saisie)
		{
			case 1:
				b.move(utilities::EDirection::TOP);
				b.showPosition();
				break;
			
			case 2:
				b.move(utilities::EDirection::BOTTOM);
				b.showPosition();
				break;

			default:
				break;
		}

	}while(saisie != 0);

	return 0;
}