#include <minesweeper/grid.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Row constructor")
{
	auto r = GENERATE(range(1, 42));
	auto row = Row{r};

	REQUIRE(row.rows == r);
}

TEST_CASE("Column constructor")
{
	auto c = GENERATE(range(1, 42));
	auto column = Column{c};

	REQUIRE(column.columns == c);
}

TEST_CASE("Bomb constructor")
{
	auto b = GENERATE(range(1, 42));
	auto bomb = Bomb{b};

	REQUIRE(bomb.bombs == b);
}
