#include "class.h"

const char* Book::Get_private_data() const {
	return author;
}

const char* Book::Get_publ_office() const {
	return publ_office;
}
	const char* Book::Get_topic() const {
		return topic;
	}

	void Book::draw_all_info() const {
		std::cout << "�����: " << author << std::endl;
		std::cout << "������������: " << publ_office << std::endl;
		std::cout << "����: " << topic << std::endl;
		std::cout << "��� �������: " << year_realease << std::endl << std::endl;
	}

	void Book::Output() {

		char symb;

		std::cout << "�������� ��� ������ ��� ������" << std::endl;
		std::cout << "1 - " << "����� " << std::endl;
		std::cout << "2 - " << "������������" << std::endl;
		std::cout << "3 - " << "����" << std::endl;
		std::cout << "4 - " << "��� �������" << std::endl;

		symb = getchar();
		getchar();

		std::cout << std::endl;

		switch (symb) {

		case '1':
			std::cout << author << std::endl;
			break;
		case '2':
			std::cout << publ_office << std::endl;
			break;
		case '3':
			std::cout << topic << std::endl;
			break;
		case '4':
			std::cout << year_realease << std::endl;
			break;
		default:
			std::cout << "������ �������� ���" << std::endl;

		}
		std::cout << std::endl;

	}

	void Book::Input() {

		char symb;

		std::cout << "�������� ��� ������ ��� �����" << std::endl;
		std::cout << "1 - " << "����� " << std::endl;
		std::cout << "2 - " << "������������" << std::endl;
		std::cout << "3 - " << "����" << std::endl;
		std::cout << "4 - " << "��� �������" << std::endl;

		symb = getchar();
		getchar();

		std::cout << std::endl;

		switch (symb) {
		case '1':
			std::cin.getline(author, 100);
			break;
		case '2':
			std::cin.getline(publ_office, 100);
			break;
		case '3':
			std::cin.getline(topic, 100);
			break;
		case '4':
			std::cin >> year_realease;
			getchar();
			break;
		default:
			std::cout << "������ �������� ���" << std::endl;
		}
	}

	Book::Book() : author("None"), topic{ "None" }, publ_office{ "None" }{
		year_realease = 0;
	}

	Book::Book(const char* author) : Book() {

		strcpy_s(this->author, author);
	}

	Book::Book(const char* author, const char* topic, const char* publ_office) : Book(author) {
		strcpy_s(this->topic, topic);
		strcpy_s(this->publ_office, publ_office);
	}

	Book::Book(const char* author, const char* topic, const char* publ_office, int year_realease) : Book(author, topic, publ_office) {
		this->year_realease = year_realease;
	}

	Book::~Book() {
		strcpy_s(author, " ");
		strcpy_s(topic, " ");
		strcpy_s(publ_office, " ");
		year_realease = -1;

		std::cout << "object deleted" << std::endl;
	}
