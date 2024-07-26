#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << CYAN"a = " << a << DEF", " PURPLE"b = " << b << DEF << std::endl;
	std::cout << ORANGE"min( a, b ) = " DEF GREEN << ::min( a, b ) << std::endl;
	std::cout << ORANGE"max( a, b ) = " DEF GREEN << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << CYAN"c = " << c << DEF", " PURPLE"d = " << d << std::endl;
	std::cout << ORANGE"min( c, d ) = " DEF GREEN << ::min( c, d ) << std::endl;
	std::cout << ORANGE"max( c, d ) = " DEF GREEN << ::max( c, d ) << std::endl;
	return 0;
}
