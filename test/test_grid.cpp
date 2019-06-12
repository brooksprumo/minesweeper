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

TEST_CASE("Grid::at()")
{
	Grid g{ Row{5}, Column{5}, Bomb{0} };

	SECTION("correct arguments don't throw")
	{
		auto row = GENERATE(range(0, 4));
		auto col = GENERATE(range(0, 4));

		REQUIRE_NOTHROW(g.at(Row{row}, Column{col}));
	}

	SECTION("out-of-range arguments throw")
	{
		REQUIRE_THROWS_AS(g.at(Row{-1}, Column{ 1}), std::range_error);
		REQUIRE_THROWS_AS(g.at(Row{ 1}, Column{-1}), std::range_error);
		REQUIRE_THROWS_AS(g.at(Row{-1}, Column{-1}), std::range_error);

		REQUIRE_THROWS_AS(g.at(Row{10}, Column{ 1}), std::range_error);
		REQUIRE_THROWS_AS(g.at(Row{ 1}, Column{10}), std::range_error);
		REQUIRE_THROWS_AS(g.at(Row{10}, Column{10}), std::range_error);
	}
}

TEST_CASE("Grid::adjacent_spaces()")
{
	Grid g{ Row{3}, Column{3}, Bomb{0} };
	std::vector<Space*> adj_spaces;

	SECTION("(0,0)")
	{
		adj_spaces.push_back(&g.at(Row{1}, Column{0}));
		adj_spaces.push_back(&g.at(Row{0}, Column{1}));
		REQUIRE_THAT(g.adjacent_spaces(Row{0}, Column{0}), Catch::Equals(adj_spaces));
	}

	SECTION("(1,1)")
	{
		adj_spaces.push_back(&g.at(Row{0}, Column{1}));
		adj_spaces.push_back(&g.at(Row{2}, Column{1}));
		adj_spaces.push_back(&g.at(Row{1}, Column{0}));
		adj_spaces.push_back(&g.at(Row{1}, Column{2}));
		REQUIRE_THAT(g.adjacent_spaces(Row{1}, Column{1}), Catch::Equals(adj_spaces));
	}

	SECTION("(2,2)")
	{
		adj_spaces.push_back(&g.at(Row{1}, Column{2}));
		adj_spaces.push_back(&g.at(Row{2}, Column{1}));
		REQUIRE_THAT(g.adjacent_spaces(Row{2}, Column{2}), Catch::Equals(adj_spaces));
	}
}
