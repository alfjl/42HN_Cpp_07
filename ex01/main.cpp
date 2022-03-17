#include <iostream>
#include "iter.hpp"

void	displayCharArray(char &character)
{
	std::cout << character << std::endl;
}

void	displayStringArray(std::string &str)
{
	std::cout << str << std::endl;
}

void	displayIntArray(int &integer)
{
	std::cout << integer<< std::endl;
}

void	displayDoubleArray(double &doublePrecision)
{
	std::cout << doublePrecision << std::endl;
}

int	main(void)
{
	char	charArray[] = {'a', 'b', 'c'};
	std::string	stringArray[] = {"one", "two", "three"};
	int	intArray[] = {1, 2, 3};
	double	doubleArray[] = {4.2, 40.20, 42.42};

	// ########## DISPLAY ########## //
	
	std::cout << " * CHAR_ARRAY: " << std::endl;
	::iter(charArray, ( sizeof(charArray) / sizeof(char) ), displayCharArray);
	std::cout << " * T: " << std::endl;
	::iter(charArray, ( sizeof(charArray) / sizeof(char) ), displayTArray);
	std::cout << std::endl;

	std::cout << " * STRING: " << std::endl;
	::iter(stringArray, ( sizeof(stringArray) / sizeof(std::string) ), displayStringArray);
	std::cout << " * T: " << std::endl;
	::iter(stringArray, ( sizeof(stringArray) / sizeof(std::string) ), displayStringArray);
	std::cout << std::endl;

	std::cout << " * INT: " << std::endl;
	::iter(intArray, ( sizeof(intArray) / sizeof(int) ), displayIntArray);
	std::cout << " * T: " << std::endl;
	::iter(intArray, ( sizeof(intArray) / sizeof(int) ), displayTArray);
	std::cout << std::endl;

	std::cout << " * DOUBLE: " << std::endl;
	::iter(doubleArray, ( sizeof(doubleArray) / sizeof(double) ), displayDoubleArray);
	std::cout << " * T: " << std::endl;
	::iter(doubleArray, ( sizeof(doubleArray) / sizeof(double) ), displayTArray);
	std::cout << std::endl;

	return (0);
}
