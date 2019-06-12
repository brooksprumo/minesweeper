#include <minesweeper/grid.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Row constructor")
{
	auto r = GENERATE(range(1, 42));
	auto rows = Row{r};

	REQUIRE(rows == r);
}

TEST_CASE("Column constructor")
{
	auto c = GENERATE(range(1, 42));
	auto columns = Column{c};

	REQUIRE(columns == c);
}

TEST_CASE("Bomb constructor")
{
	auto b = GENERATE(range(1, 42));
	auto bombs = Bomb{b};

	REQUIRE(bombs == b);
}
