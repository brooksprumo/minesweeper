#pragma once
#include "grid.hpp"

class Minesweeper
{
	private:
		Grid grid_;

	public:
		Minesweeper(Grid grid);
		void play();
};
