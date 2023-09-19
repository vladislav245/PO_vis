#include <iostream>
#include "Book.h"


void Delete(Book*& ptr) {
	delete ptr;
	ptr = nullptr;
}

int main()
{

	setlocale(LC_ALL, "RUS");

	//без параметров 
	Book* empty = new Book;

	//с параметрами
	Book* obj1 = new Book("Pushkin");

	Book* obj2 = new Book("Tolstoy", "War and Peace", "Eksmo");

	Book* obj3 = new Book("Dostoevsky", "Crime and Punishment", "Rosmen", 1876);

	Book* arr_obj[3]{ nullptr };

	//1
	while (true) {
		int number;
		int var;

		std::cout << "Выберете объект" << std::endl;
		std::cout << "1 - пустой объект" << std::endl;
		std::cout << "2 - объект с 1 параметром" << std::endl;
		std::cout << "3 - объект с 3 параметрами" << std::endl;
		std::cout << "4 - объект с 4 параметрами" << std::endl;
		std::cout << "5 - закончить" << std::endl;

		std::cin >> number;
		getchar();
		check_output();

		if (number == 5) break;

		std::cout << std::endl;
		std::cout << "1 - Ввести данные" << std::endl;
		std::cout << "2 - Удалить объект" << std::endl;

		std::cin >> var;
		getchar();
		check_output();

		if (var < 1 || var > 2) {
			std::cout << std::endl << "Такого варианта нет" << std::endl << std::endl;
			continue;
		}

		std::cout << std::endl << std::endl;

		switch (number) {
		case 1:
			if (empty == nullptr) {
				std::cout << "Объект удален" << std::endl;
			}
			else if (var == 1) {
				empty->Input();
				empty->Draw_all_info();
			}
			
			else if(var == 2){
				Delete(empty);
			}
			break;
		case 2:
			if (obj1 == nullptr) {
				std::cout << "Объект удален" << std::endl;
			}
			else if (var == 1) {
				obj1->Input();
				obj1->Draw_all_info();
			}
			
			else if(var == 2){
				Delete(obj1);
			}
			break;
		case 3:
			if (obj2 == nullptr) {
				std::cout << "Объект удален" << std::endl;
			}
			else if (var == 1) {
				obj2->Input();
				obj2->Draw_all_info();
			}
			
			else if (var == 2) Delete(obj2);
			break;
		case 4:
			if (obj3 == nullptr) {
				std::cout << "Объект удален" << std::endl;
			}
			else if (var == 1) {
				obj3->Input();
				obj3->Draw_all_info();
			}
			
			else if (var == 2) Delete(obj3);
			break;
		default:
			std::cout << "Такого варианта нет" << std::endl;
		}

		std::cout << std::endl << std::endl;

	}

	std::cout << std::endl << std::endl << "Заполняем массив" << std::endl;

	while (true) {
		int var;
		int number;

		std::cout << "Выберете номер объекта от 1 до 3" << std::endl;
		std::cout << "4 - закончить" << std::endl;

		std::cin >> number;
		getchar();
		check_output();

		if (number == 4) break;

		number--;

		if (number < 0 || number >= 3) {
			std::cout << std::endl << "Данного варианта нет" << std::endl << std::endl;
			continue;
		}


		std::cout << std::endl;
		std::cout << "1 - Ввести данные\n2 - Вывести выбранные данные\n3 - Вывести все данные\n4 - Удалить объект" << std::endl;

		std::cin >> var;
		getchar();
		check_output();

		if (var < 0 || var > 4) {
			std::cout << std::endl << "Данного варианта нет" << std::endl << std::endl;
			continue;
		}

		if (arr_obj[number] == nullptr) {
			std::cout << std::endl << "Создан новый объект" << std::endl << std::endl;
			arr_obj[number] = new Book;
		}

		if (var == 1) arr_obj[number]->Input();
		else if (var == 2) arr_obj[number]->Output();
		else if (var == 3) arr_obj[number]->Draw_all_info();
		else if (var == 4) Delete(arr_obj[number]);
		else std::cout << std::endl << "Данного варианта нет" << std::endl << std::endl;

		std::cout << std::endl;
	}

}
