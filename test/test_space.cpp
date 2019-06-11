#include <minesweeper/space.hpp>
#include <catch2/catch.hpp>

TEST_CASE("test Space")
{
	SECTION("default Space constructor")
	{
		Space s;
		REQUIRE_FALSE(s.contains_bomb());
	}

	SECTION("initialize Space without bomb")
	{
		Space s{false};
		REQUIRE_FALSE(s.contains_bomb());
		s.set_contains_bomb(true);
		REQUIRE(s.contains_bomb());
	}

	SECTION("initialize Space with bomb")
	{
		Space s{true};
		REQUIRE(s.contains_bomb());
		s.set_contains_bomb(false);
		REQUIRE_FALSE(s.contains_bomb());
	}
}

TEST_CASE("test HiddenSpace")
{
	HiddenSpace s;
	REQUIRE_FALSE(s.contains_bomb());
}
