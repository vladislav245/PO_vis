#include <iostream>

#pragma warning(disable:4996)

void check_output();

class Book {

	void Delete_obj();

	char* author;  //�����

	const char* Get_private_data() const;

protected:
	char* __new_char__();

	char* publ_office; // ������������
	char* topic;   //����

	const char* Get_publ_office() const;

	const char* Get_topic() const;

public:

	int year_realease; // ��� �������

	Book(const Book& tmp);

	void Output() const;

	void Input();

	Book(const char* author = "None", const char* topic = "None", const char* publ_office = "None", int year_realease = 40, bool flag = 0);

	~Book();

};

//��������� �����
class Scripture : public Book {

	char* religion;

public:

	Scripture(const char* religion, const char* author = "None", const char* topic = "None",
		const char* publ_office = "None", int year_realease = 40, bool flag = 0);

	Scripture(const Scripture& tmp);
 
	void Output() const;

	void Input();

	~Scripture();

};

class Magazine : public Book {

	int size_news;
	
public:

	Magazine(int size_news, const char* author = "None", const char* topic = "None",
		const char* publ_office = "None", int year_realease = 40, bool flag = 0);

	Magazine(const Magazine& tmp);

	void Output() const;

	void Input();

};

//��������� ������
class AD_Magazine : public Magazine{

	char* ad_theme;

public:

	AD_Magazine(const char* ad_theme, int size_news, const char* author = "None", const char* topic = "None",
		const char* publ_office = "None", int year_realease = 40, bool flag = 0);

	AD_Magazine(const AD_Magazine& tmp);

	void Output() const;

	void Input();

	~AD_Magazine();
};