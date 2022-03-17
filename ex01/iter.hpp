#pragma once

#include <string>

template< typename T >
void	displayTArray(T &t)
{
	std::cout << t << std::endl;
}

template< typename T >
void	iter(T *array, size_t length, void (*fkt)(T &))
{
	if (array == nullptr || fkt == nullptr)
		return ;

	for (size_t i = 0; i < length; i++)
		fkt(array[i]);
}
