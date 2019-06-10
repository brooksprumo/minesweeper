#include <fmt/format.h>
#include <fmt/ostream.h>
#include <clara.hpp>
#include "grid.hpp"

int main(int argc, char *argv[])
{
	int rows = 5;
	int columns = 10;

	auto cli = clara::Opt(rows, "rows")
	                      ["-r"]["--rows"]
	                      ("How many rows should there be?")
	         | clara::Opt(columns, "columns")
	                      ["-c"]["--columns"]
	                      ("How many columns should there be?");

	const auto result = cli.parse(clara::Args(argc, argv));
	if (!result) {
		fmt::print(stderr, "Error in command line: {}\n", result.errorMessage());
		exit(1);
	}

	const auto grid = Grid{ Row{rows}, Column{columns} };
	fmt::print("Printing {}x{} grid:\n{}\n", rows, columns, grid);
	return 0;
}
