#include <iostream>
#include <algorithm>
#include <vector>
#include "class.h"

using namespace std;

bool empty(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
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

int minimumTimeRequired(vector<int>& arr, int k) {

	std::sort(arr.begin(), arr.end());

	int size = arr.size();
	int* res = new int[k] {0};
	int mid = 0;

	for (int i = 0; i < size; i++) {
		mid += arr[i];
	}
	mid = std::ceil(float(mid) / k);
	int max = mid;

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

	while (empty(arr) != 1) {

		int* ptr = my_min(res, k);

		for (int j = size - 1; j > -1; j--) {
			if (*ptr + arr[j] > max) {
				*ptr += arr[j];
				max = *ptr;
				arr[j] = 0;
			}
		}
	}

	return std::max(*res, *(res) + k);
}

int main()
{

	setlocale(LC_ALL, "RUS");
	//массив времени
	
	vector<int> arr{ 1, 24, 62, 55, 1, 22, 14, 55, 2, 17, 14 };
	
	int sum = minimumTimeRequired(arr, 3);

	cout << "\n\n" << sum << endl;

	return 0;
}
