#include <catch.hpp>
#include <minesweeper/grid.hpp>

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
