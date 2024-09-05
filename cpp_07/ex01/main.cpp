#include "iter.hpp"

int	main(void) {
	std::cout << PURPLE"\tTEST AN ARRAY OF CHAR" << std::endl;
	char	char_arr[] = "hello world";
	iter(char_arr, 11, &print);

	std::cout << std::endl << DEF GREEN"\tTEST AN ARRAY OF STRING" << std::endl;
	std::string	str_arr[] = {"Foo", "Bar", "Baz"};
	iter(str_arr, 3, &print);

	std::cout << std::endl << DEF YELLOW"\tTEST AN ARRAY OF INT" << std::endl;
	int		int_arr[] = {18, 5, 36, 150};
	iter(int_arr, 4, &print);

	std::cout << std::endl << DEF CYAN"\tTEST AN ARRAY OF DOUBLE" << std::endl;
	double	double_arr[] = { 18.5f, 5.0f, 36.758f, 150.45f};
	iter(double_arr, 4, &print);
	std::cout << DEF << std::endl;

	return (0);
}

