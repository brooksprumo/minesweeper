#pragma once
#include <vector>
#include <iostream>
#include "space.hpp"

class Row
{
	public:
		int rows;

	public:
		explicit Row(int r);
};

class Column
{
	public:
		int columns;

	public:
		explicit Column(int c);
};

class Grid
{
	public:
		Row rows_;
		Column columns_;

		std::vector<Space> spaces_;

	public:
		Grid(Row rows, Column columns);
		friend std::ostream & operator<<(std::ostream & os, const Grid & grid);
};

