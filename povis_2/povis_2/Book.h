#include <iostream>

#pragma warning(disable:4996)

void check_output();

class Book {

	char* __new_char__();

	void Delete_obj();

	char* author;  //�����

	const char* Get_private_data() const;

protected:
	char* publ_office; // ������������
	char* topic;   //����

	const char* Get_publ_office() const;

	const char* Get_topic() const;

public:

	int year_realease; // ��� �������


	void Draw_all_info() const;

	void Output();

	void Input();

	Book();

	Book(const char* author);

	Book(const char* author, const char* topic, const char* publ_office);

	Book(const char* author, const char* topic, const char* publ_office, int year_realease);

	~Book();

};