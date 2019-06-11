#include <random>
#include "grid.hpp"

Row::Row(int r)
	: rows{r}
{
}

Column::Column(int c)
	: columns{c}
{
}

Bomb::Bomb(int b)
	: bombs{b}
{
}

Grid::Grid(Row rows, Column columns, Bomb bombs)
	: rows_{rows}
	, columns_{columns}
	, bombs_{bombs}
{
	const auto number_of_spaces = rows_.rows * columns_.columns;
	spaces_.resize(number_of_spaces);

	auto rng = std::default_random_engine();
	for (auto i = 0; i != bombs.bombs; ++i)
	{
		const auto index = rng() % number_of_spaces;
		if (spaces_[index].contains_bomb())
		{
			continue;
		}
		spaces_[index].set_contains_bomb(true);
	}
}

std::ostream & operator<<(std::ostream & os, const Grid & grid)
{
	const auto columns = grid.columns_.columns;

	// output column numbers
	// skip the row number
	os << ' ';
	for (auto c = 0; c != columns; ++c)
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
		if (++col < columns)
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
