#include <iostream>
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

	auto result = cli.parse(clara::Args(argc, argv));
	if (!result) {
		std::cerr << "Error in command line: " << result.errorMessage() << std::endl;
		exit(1);
	}

	auto grid = Grid{ Row{rows}, Column{columns} };
	std::cout << "Printing " << rows << "x" << columns << " grid:\n" << grid << std::endl;
	return 0;
}
