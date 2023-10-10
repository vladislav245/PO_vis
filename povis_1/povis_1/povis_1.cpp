#include <iostream>
#include <algorithm>
#include <vector>
#include "class.h"

using namespace std;

bool empty(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] != 0) return 0;
	}
	return 1;
}

int* my_min(int* arr, int size) {
	int* ptr = nullptr;

	int min = 1000000;
	for (int i = 0; i < size; i++) {
		if (arr[i] <= min) {
			ptr = &arr[i];
			min = arr[i];
		}
	}
	return ptr;
}

int main()
{

	setlocale(LC_ALL, "RUS");
	
	//массив времени
	int* arr;
	int size;

	cout << "Введите кол-во работы" << endl;
	cin >> size;
	
	arr = new int[size];

	cout << "Время" << endl;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	std::sort(arr, arr + size);

	//рабочие
	int k;
	cout << "Введите кол-во работников" << endl;
	cin >> k;

	int* res = new int[k] {0};

	int mid = 0;

	for (int i = 0; i < size; i++) {
		mid += arr[i];
	}
	mid = std::ceil(float(mid) / k);
	//макс время 1-ой работы
	int max = mid;

	cout << "СР ЗНАЧ = " << mid << endl;

	//если есть работа больше средней по времени
	int step = 0;
	for (int i = 0; i < k; i++) {
		for (int j = size - 1; j > -1; j--) {
			if (arr[j] > max) {
				max = arr[j];
				res[i] = arr[j];
				arr[j] = 0;
				step++;
			}
		}
	}

	for (int i = 0 + step; i < k; i++) {
		for (int j = size - 1; j > -1; j--) {
			if (res[i] + arr[j] <= max) {
				res[i] += arr[j];
				arr[j] = 0;
			}
		}
	}

	for (int i = 0; i < k; i++) {
		cout << res[i] << endl;
	}

	while (empty(arr, size) != 1) {
		
		int* ptr = my_min(res, k);

		for (int j = size - 1; j > -1; j--) {
			if (*ptr + arr[j] > max) {
				*ptr += arr[j];
				max = *ptr;
				arr[j] = 0;
			}
		}
	}

	cout << endl;

	for (int i = 0; i < k; i++) {
		cout << res[i] << endl;
	}

	return 0;
}
