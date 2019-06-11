#include "space.hpp"

Space::Space(bool contains_bomb)
	: contains_bomb_{contains_bomb}
{
}

bool Space::contains_bomb() const
{
	return contains_bomb_;
}

void Space::set_contains_bomb(bool contains_bomb)
{
	contains_bomb_ = contains_bomb;
}

HiddenSpace::HiddenSpace(bool contains_bomb)
	: Space(contains_bomb)
	, revealed_{false}
{
}

std::ostream & operator<<(std::ostream & os, const Space & space)
{
	os << (space.contains_bomb_ ? '!' : '-');
	return os;
}

std::ostream & operator<<(std::ostream & os, const HiddenSpace & space)
{
	if (space.revealed_)
	{
		os << static_cast<const Space &>(space);
	}
	else
	{
		os << 'x';
	}

	return os;
}
