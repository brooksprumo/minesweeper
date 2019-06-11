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

class Bomb
{
	public:
		int bombs;

	public:
		explicit Bomb(int b);
};

class Grid
{
	public:
		const Row rows_;
		const Column columns_;
		const Bomb bombs_;

		std::vector<Space> spaces_;

	public:
		Grid(Row rows, Column columns, Bomb bombs);
		friend std::ostream & operator<<(std::ostream & os, const Grid & grid);
};

