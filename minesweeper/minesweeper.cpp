#include <iostream>
#include "minesweeper.hpp"

Minesweeper::Minesweeper(Grid grid)
	: grid_{grid}
{
}


void Minesweeper::play()
{

	//
	// print grid
	//
	// ask what to do next
	//
	// validate input
	//
	// execute input
	//
	// break if solved
	// else loop
	//


	while (1)
	{
		std::cout << grid_ << "\n\n";

		std::cout << "Specify a space to reveal: ";
		int row;
		int col;
		std::cin >> row >> col;

		if (row < 0 || col < 0)
		{
			break;
		}
	}

}
