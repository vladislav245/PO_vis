#pragma once

#include <iostream>

#pragma warning(disable:4996)

void check_output();

class Intarface{

public:
	virtual void Output() const = 0;
	virtual void Input() = 0;
	virtual ~Intarface() { };
};

class Book : public Intarface {

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

	virtual void Output() const;

	virtual void Input();

	Book(const char* author = "None", const char* topic = "None", const char* publ_office = "None", int year_realease = 40, bool flag = 0);

	virtual ~Book();

};

//��������� �����
class Scripture : virtual public Book {

	char* religion;

public:

	Scripture(const char* religion, const char* author = "None", const char* topic = "None",
		const char* publ_office = "None", int year_realease = 40, bool flag = 0);

	Scripture(const Scripture& tmp);

	virtual void Output() const;

	virtual void Input();

	virtual ~Scripture();

};

class Magazine : virtual public Book {

	int size_news;

public:

	Magazine(int size_news, const char* author = "None", const char* topic = "None",
		const char* publ_office = "None", int year_realease = 40, bool flag = 0);

	Magazine(const Magazine& tmp);

	virtual void Output() const;

	virtual void Input();

};

//��������� ������
class AD_Magazine : public Magazine, public Scripture {

	char* ad_theme;

public:



	AD_Magazine(const char* ad_theme, int size_news, const char* author = "None", const char* topic = "None",
		const char* publ_office = "None", int year_realease = 40, bool flag = 0);

	AD_Magazine(const AD_Magazine& tmp);

	bool operator > (const char* ptr);

	void operator &= (const char* ptr);

	friend bool operator > (const char* ptr, const AD_Magazine& obj1);
	friend void operator &= (char*& ptr, const AD_Magazine& obj1);

	virtual ~AD_Magazine();
};
