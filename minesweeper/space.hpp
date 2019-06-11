#pragma once
#include <iostream>

class Space
{
	private:
		bool contains_bomb_;

	public:
		explicit Space(bool contains_bomb = false);
		bool contains_bomb() const;
		void set_contains_bomb(bool contains_bomb);
		friend std::ostream & operator<<(std::ostream & os, const Space & space);
};

class HiddenSpace : public Space
{
	private:
		bool revealed_;

	public:
		explicit HiddenSpace(bool contains_bomb = false);
		friend std::ostream & operator<<(std::ostream & os, const HiddenSpace & space);
};
