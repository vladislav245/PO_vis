#include <iostream>

class Book {

	static int constexpr SIZE = 100;

	char author[SIZE];  //автор

	const char* Get_private_data() const;

protected:
	char publ_office[SIZE]; // издательство
	char topic[SIZE];   //тема

	const char* Get_publ_office() const;

	const char* Get_topic() const;

public:

	int year_realease; // год издания


	void draw_all_info() const;

	void Output();

	void Input();

	Book();

	Book(const char* author);

	Book(const char* author, const char* topic, const char* publ_office);

	Book(const char* author, const char* topic, const char* publ_office, int year_realease);

	~Book();

};