#pragma once
#include <vector>
#include <iostream>
#include "space.hpp"

class Row
{
	public:
		int val_;

	public:
		explicit Row(int rows);
		operator int() const;
};

class Column
{
	public:
		int val_;

	public:
		explicit Column(int columns);
		operator int() const;
};

class Bomb
{
	public:
		int val_;

	public:
		explicit Bomb(int bombs);
		operator int() const;
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
		Space & at(Row row, Column col);
		std::vector<Space*> adjacent_spaces(Row row, Column col);
		friend std::ostream & operator<<(std::ostream & os, const Grid & grid);
};

