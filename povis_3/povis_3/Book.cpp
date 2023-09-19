#include "Book.h"

#pragma warning(disable:4996)

void check_output() {
	if (!std::cin) {
		std::cin.clear();
		std::cin.ignore();
	}
}

char* Book::__new_char__() {

	std::cout << "Чтобы закончить нажмите /" << std::endl;

	char c = ' ';
	char* str = nullptr;
	int capacity = 1;
	int size = 0;
	while (true) {

		size++;

		if (size >= capacity) {
			capacity *= 2;

			if (str == nullptr) {
				str = new char[capacity];
			}
			else {
				char* tmp = str;
				tmp = str;
				tmp[size - 1] = '\0';
				str = new char[capacity];
				strcpy(str, tmp);

				delete[] tmp;
			}
		}

		c = std::cin.get();
		if (c == '/') break;

		if (std::cin.peek() == '\n') std::cin.get();


		str[size - 1] = c;
	}

	getchar();
	check_output();
	str[size - 1] = '\0';

	return str;
}

void Book::Delete_obj() {
	this->~Book();
}

const char* Book::Get_private_data() const {
	return author;
}

const char* Book::Get_publ_office() const {
	return publ_office;
}
const char* Book::Get_topic() const {
	return topic;
}

Book::Book(const Book& tmp) {

	std::cout << "Конструктор копирования" << std::endl;

	if (this == &tmp) {
		std::cout << std::endl << "Нельзя копировать самого себя" << std::endl;
		return;
	}

	this->author = new char[strlen(tmp.author) + 1];
	strcpy(this->author, tmp.author);
	this->publ_office = new char[strlen(tmp.publ_office) + 1];
	strcpy(this->publ_office, tmp.publ_office);
	this->topic = new char[strlen(tmp.topic) + 1];
	strcpy(this->topic, tmp.topic);
	this->year_realease = tmp.year_realease;
}

void Book::Draw_all_info() const {
	std::cout << std::endl;
	std::cout << "Автор: " << author << std::endl;
	std::cout << "издательство: " << publ_office << std::endl;
	std::cout << "тема: " << topic << std::endl;
	std::cout << "год издания: " << year_realease << std::endl << std::endl;
}

void Book::Output() {

	int number;

	std::cout << "Выберите тип данных для вывода" << std::endl;
	std::cout << "1 - " << "Автор " << std::endl;
	std::cout << "2 - " << "Издательство" << std::endl;
	std::cout << "3 - " << "Тема" << std::endl;
	std::cout << "4 - " << "Год издания" << std::endl;

	std::cin >> number;
	getchar();
	check_output();

	std::cout << std::endl;

	switch (number) {

	case 1:
		std::cout << author << std::endl;
		break;
	case 2:
		std::cout << publ_office << std::endl;
		break;
	case 3:
		std::cout << topic << std::endl;
		break;
	case 4:
		std::cout << year_realease << std::endl;
		break;
	default:
		std::cout << "Такого варианта нет" << std::endl;

	}
	std::cout << std::endl;

}

void Book::Input() {

	int number;

	std::cout << "Выберите тип данных для ввода" << std::endl;
	std::cout << "1 - " << "Автор " << std::endl;
	std::cout << "2 - " << "издательство" << std::endl;
	std::cout << "3 - " << "тема" << std::endl;
	std::cout << "4 - " << "год издания" << std::endl << std::endl;

	std::cin >> number;
	getchar();
	check_output();

	std::cout << std::endl;

	switch (number) {
	case 1:
		author = __new_char__();
		break;
	case 2:
		publ_office = __new_char__();
		break;
	case 3:
		topic = __new_char__();
		break;
	case 4:
		std::cin >> year_realease;
		getchar();
		check_output();
		break;
	default:
		std::cout << "Такого варианта нет" << std::endl;
	}

	std::cout << std::endl << std::endl;
}

Book::Book(const char* author, const char* topic, const char* publ_office, int year_realease, bool flag){

	if (flag == 0) {
		this->author = new char[strlen(author) + 1];
		strcpy(this->author, author);
		this->topic = new char[strlen(topic) + 1];
		strcpy(this->topic, topic);
		this->publ_office = new char[strlen(publ_office) + 1];
		strcpy(this->publ_office, publ_office);
	}
	else {
		this->author = const_cast<char*>(author);
		this->topic = const_cast<char*>(topic);
		this->publ_office = const_cast<char*>(publ_office);
	}

	this->year_realease = year_realease;
}

Book::~Book() {
	if (author != nullptr) {
		delete author;
		author = nullptr;
	}
	if (topic != nullptr) {
		delete topic;
		topic = nullptr;
	}
	if (publ_office != nullptr) {
		delete publ_office;
		publ_office = nullptr;
	}
	year_realease = -1;

	std::cout << "object deleted" << std::endl;
}
