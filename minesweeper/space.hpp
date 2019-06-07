#pragma once

#include <iostream>

class Space
{
	public:
		friend std::ostream & operator<<(std::ostream & os, const Space & space);
};
