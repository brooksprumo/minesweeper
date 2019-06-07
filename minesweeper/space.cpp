#include "space.hpp"

Space::Space(bool contains_bomb)
	: contains_bomb_{contains_bomb}
	, revealed_{false}
{
}

std::ostream & operator<<(std::ostream & os, const Space & space)
{
	if (space.revealed_)
	{
		os << (space.contains_bomb_ ? '!' : '-');
	}
	else
	{
		os << 'x';
	}

	return os;
}
