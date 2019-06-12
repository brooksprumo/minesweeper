#include <random>
#include <stdexcept>
#include <fmt/core.h>
#include "grid.hpp"

Row::Row(int rows)
	: val_{rows}
{
}

Row::operator int() const
{
	return val_;
}

Column::Column(int columns)
	: val_{columns}
{
}

Column::operator int() const
{
	return val_;
}

Bomb::Bomb(int bombs)
	: val_{bombs}
{
}

Bomb::operator int() const
{
	return val_;
}

Grid::Grid(Row rows, Column columns, Bomb bombs)
	: rows_{rows}
	, columns_{columns}
	, bombs_{bombs}
{
	const auto number_of_spaces = rows_ * columns_;
	spaces_.resize(number_of_spaces);

	// add bombs
	auto rng = std::default_random_engine();
	for (auto i = 0; i != bombs; ++i)
	{
		const auto index = rng() % number_of_spaces;
		if (spaces_[index].contains_bomb())
		{
			continue;
		}
		spaces_[index].set_contains_bomb(true);
	}
}
Space & Grid::at(Row row, Column col)
{
	if (row < 0 || row >= rows_) throw std::range_error(fmt::format("Error: 'row' out of range! row: {}, rows_: {}", row, rows_));
	if (col < 0 || col >= columns_) throw std::range_error(fmt::format("Error: 'col' out of range! col: {}, columns_: {}", col, columns_));
	return spaces_[row * rows_ + col];
}

std::vector<Space*> Grid::adjacent_spaces(Row row, Column col)
{
	std::vector<Space*> adjacent_spaces;

	try { adjacent_spaces.push_back(&at(Row{row-1}, col)); }
	catch (const std::range_error &) { }

	try { adjacent_spaces.push_back(&at(Row{row+1}, col)); }
	catch (const std::range_error &) { }

	try { adjacent_spaces.push_back(&at(row, Column{col-1})); }
	catch (const std::range_error &) { }

	try { adjacent_spaces.push_back(&at(row, Column{col+1})); }
	catch (const std::range_error &) { }

	return adjacent_spaces;
}

std::ostream & operator<<(std::ostream & os, const Grid & grid)
{
	// output column numbers
	// skip the row number
	os << ' ';
	for (auto c = 0; c != grid.columns_; ++c)
	{
		os << ' ' << c ;
	}
	os << '\n';

	auto row = 0;
	auto col = 0;

	for (auto && s: grid.spaces_)
	{
		// output the row number
		if (col == 0)
		{
			if (row != 0)
			{
				os << '\n';
			}
			os << row << ' ';
		}

		// output the space
		os << s;

		// figure out if at the end of the column
		if (++col < grid.columns_)
		{
			os << ' ';
		}
		else
		{
			++row;
			col = 0;
		}
	}

	return os;
}
