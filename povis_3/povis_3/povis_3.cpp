#include <iostream>
#include "Book.h"


void Delete(Book*& ptr) {
	delete ptr;
	ptr = nullptr;
}

int main()
{

	setlocale(LC_ALL, "RUS");

	
	Book* obj1 = new Book("Tolstoy", "War and Peace");
	Book* obj2 = new Book(*obj1);
 
	obj1->Draw_all_info();
	obj2->Draw_all_info();

	Delete(obj1);

	obj2->Draw_all_info();

	Delete(obj2);

	// // // // //

	char* str = new char []{ "vlad" };

	obj1 = new Book;
	obj2 = new Book(str, "Crime and Punishment", "Rosmen", 1876, 1);
	Book* obj3 = new Book("Tolstoy", "War and Peace", "Eksmo");

	return 0;
}

