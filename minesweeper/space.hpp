#pragma once
#include <iostream>

class Space
{
	private:
		bool contains_bomb_;
		bool revealed_;

	public:
		explicit Space(bool contains_bomb = false);
		friend std::ostream & operator<<(std::ostream & os, const Space & space);
};
