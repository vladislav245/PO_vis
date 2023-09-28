#include <iostream>
#include <locale>
#include "Book.h"


bool operator > (const char* ptr, const AD_Magazine& obj1){

	int step = 0;

	int size = strlen(ptr);
	while (step != 5 && size > 0) {

		if (ptr[size - 1] > obj1.ad_theme[step]) return 1;
		else if (ptr[size - 1] < obj1.ad_theme[step]) return 0;
		else {
			step++;
			size--;
		}
	}

	return 0;
}

void operator &= (char*& ptr, AD_Magazine& obj1) {

	if (ptr == nullptr || obj1.ad_theme == nullptr) return;

	int size = strlen(ptr);

	char* tmp;
	if (size <= 5) {
		delete[] ptr;
		ptr = new char[strlen(obj1.ad_theme) + 1];

		strcpy(ptr, obj1.ad_theme);
		return;
	}

	else {
		int s = (size - 5) + strlen(obj1.ad_theme) + 1;
		tmp = ptr;
		ptr = new char[s];

		strncpy(ptr, obj1.ad_theme, size - 5);
		ptr[size - 5] = '\0';
		strcat(ptr, obj1.ad_theme);
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	AD_Magazine obj1("a23456", 25, "va", "!");
	Magazine obj2(236);

	obj1.Output();
	obj2.Output();


	std::cout << (obj1 > &obj2) << std::endl;
	
	return 0;
}