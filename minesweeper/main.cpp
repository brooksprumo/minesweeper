#include <fmt/ostream.h>
#include <clara.hpp>
#include "minesweeper.hpp"

int main(int argc, char *argv[])
{
	int rows = 5;
	int columns = 10;
	int bombs = 20;

	auto cli = clara::Opt(rows, "rows")
	                      ["-r"]["--rows"]
	                      ("How many rows should there be?")
	         | clara::Opt(columns, "columns")
	                      ["-c"]["--columns"]
	                      ("How many columns should there be?")
	         | clara::Opt(bombs, "bombs")
	                      ["-b"]["--bombs"]
	                      ("How many bombs should there be?");

	const auto result = cli.parse(clara::Args(argc, argv));
	if (!result) {
		fmt::print(std::cerr, "Error in command line: {}\n", result.errorMessage());
		exit(1);
	}

	if (bombs >= rows * columns)
	{
		fmt::print("Error: Too many bombs! The number of bombs must be less than the number of spaces on the board (i.e. bombs < rows * columns)\n\trows: {}\n\tcolumns: {}\n\tbombs: {}", rows, columns, bombs);
		exit(1);
	}

	Minesweeper minesweeper{ Grid{ Row{rows}, Column{columns}, Bomb{bombs} } };
	minesweeper.play();

	return 0;
}
