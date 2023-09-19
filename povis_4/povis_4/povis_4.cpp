#include <iostream>
#include "Book.h"


int main()
{

	setlocale(LC_ALL, "RUS");


	Scripture obj1("Christianity");

	obj1.Output();
	getchar();

	obj1.Input();

	std::cout << std::endl << std::endl << "Результат" << std::endl;
	obj1.Output();
	getchar();

	Magazine obj2(3, "Vlad", "policy", "New York Nimes", 0);

	obj2.Output();
	getchar();

	obj2.Input();

	std::cout << std::endl << std::endl << "Результат" << std::endl;
	obj2.Output();
	getchar();

	AD_Magazine obj3("clothes", 6, "Bob");

	obj3.Output();
	getchar();

	obj3.Input();

	std::cout << std::endl << std::endl << "Результат" << std::endl;
	obj3.Output();
	getchar();

	return 0;
}

