#include <iostream>

#pragma warning(disable:4996)

void check_output();

class Book {

	char* __new_char__();

	void Delete_obj();

	char* author;  //автор

	const char* Get_private_data() const;

protected:
	char* publ_office; // издательство
	char* topic;   //тема

	const char* Get_publ_office() const;

	const char* Get_topic() const;

public:

	int year_realease; // год издания

	Book(const Book& tmp);

	virtual void Draw_all_info() const;

	virtual void Output();

	virtual void Input();

	Book(const char* author = "None", const char* topic = "None", const char* publ_office = "None", int year_realease = 40, bool flag = 0);

	~Book();

};


class 