#include <iostream>
#include "class.h"


int main()
{

	setlocale(LC_ALL, "RUS");
	
	//без параметров 
	Book empty;
	
	//с параметрами
	Book obj1("Pushkin");

	Book obj2("Tolstoy", "War and Peace", "Eksmo");

	Book obj3("Dostoevsky", "Crime and Punishment", "Rosmen", 1876);

	Book arr_obj[3];

	//1
	while (true) {
		char symbol;

		std::cout << "Выберете объект" << std::endl;
		std::cout << "1 - пустой объект" << std::endl;
		std::cout << "2 - объект с 1 параметром" << std::endl;
		std::cout << "3 - объект с 3 параметрами" << std::endl;
		std::cout << "4 - объект с 4 параметрами" << std::endl;
		std::cout << "/ - закончить" << std::endl;

		symbol = getchar();
		getchar();

		if (symbol == '/') break;

		std::cout << std::endl;

		switch (symbol){
		case '1':
			empty.Input();
			empty.draw_all_info();
			break;
		case '2':
			obj1.Input();
			obj1.draw_all_info();
			break;
		case '3':
			obj2.Input();
			obj2.draw_all_info();
			break;
		case '4':
			obj3.Input();
			obj3.draw_all_info();
			break;
		default:
			std::cout << "Такого варианта нет" << std::endl;
		}
	}

	std::cout << std::endl << std::endl << "Заполняем массив" << std::endl;

	while (true) {
		char symbol;
		int number;

		std::cout << "Выберете номер объекта от 1 до 3" << std::endl;
		std::cout << "4 - закончить" << std::endl;

		std::cin >> number;
		getchar();

		if (number == 4) break;

		number--;

		if (number < 0 || number >= 3) {
			std::cout << "Данного индекса нет" << std::endl;
			continue;
		}


		std::cout << std::endl;
		std::cout << "1 - Ввести данные\n2 - Вывести выбранные данные\n3 - Вывести все данные" << std::endl;

		symbol = getchar();
		getchar();
		
		if (symbol == '1') arr_obj[number].Input();
		else if (symbol == '2') arr_obj[number].Output();
		else if (symbol == '3') arr_obj[number].draw_all_info();
		else std::cout << "Данного варианта нет" << std::endl;

		std::cout << std::endl;
	}

}
