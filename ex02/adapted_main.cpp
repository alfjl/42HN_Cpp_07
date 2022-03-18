#include <iostream>
#include "Array.hpp"

#define MAX_VAL 7500
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        //const int value = rand();
        const int value = i;
        numbers[i] = value;
        mirror[i] = value;
    }
	//SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

	// OWN TEST
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << "numbers[i]: " << numbers[i] << " / mirror[i]: " << mirror[i] << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
	for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	// OWN TEST
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << "numbers[i]: " << numbers[i] << " / mirror[i]: " << mirror[i] << std::endl;
	std::cout << "HERE!!!!!!!!!!" << std::endl;
    delete [] mirror;//
    return 0;
}


//#define MAX_VAL 750
//int main(int, char**)
//{
	//Array<int> array1(5);
	//for (int i = 0; i < 5; i++)
		//array1[i] = i;
	//std::cout << "array1:\n";
	//for (int i = 0; i < 5; i++)
		//std::cout << array1[i] << std::endl;
//
	//std::cout << std::endl;
//
	//Array<int> array2;
	//array2 = array1;
	//std::cout << "array2:\n";
	//for (int i = 0; i < 5; i++)
		//std::cout << array2[i] << std::endl;
	//for (int i = 0; i < 5; i++)
		//array2[i] = 4 - i;
	//std::cout << "unchanged array1:\n";
	//for (int i = 0; i < 5; i++)
		//std::cout << array1[i] << std::endl;
	//std::cout << "changed array2:\n";
	//for (int i = 0; i < 5; i++)
		//std::cout << array2[i] << std::endl;
//
	//std::cout << std::endl;
//
	//std::cout << "array3:\n";
	//Array<int> array3(array2);
	//for (int i = 0; i < 5; i++)
		//std::cout << array3[i] << std::endl;
	//
	//return 0;
//}

//int main()
//{
	//Array<int> arr(10);
	//for (unsigned int i = 0; i < arr.size(); i++)
	//{
		//arr[i] = i + 1;
	//}
	//for (unsigned int i = 0; i < arr.size() ; i++)
	//{
		//std::cout << arr[i] << std::endl;
	//}
	//Array<int> arr2(arr);
	//for (unsigned int i = 0; i < arr.size() ; i++)
	//{
		//std::cout << arr2[i] << std::endl;
	//}
	//Array<std::string> s;
//}
