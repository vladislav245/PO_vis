#pragma once

#include "Header.h"
#include <vector>

class binary_tree {

private:

	class class_ptr {

	public:

		void find_path(int ind, string* path);

		Interface* obj; //указатель на объект
		class_ptr* left;   //указатель на левый элемент
		class_ptr* right;  //указатель на правый элемент
		int ind;

		class_ptr();
		class_ptr(Interface* obj, int index);
	};

	void display_tree(class_ptr* tree, int space, char direction);

	class_ptr* cl_ptr;

public:

	binary_tree() { cl_ptr = nullptr; };

	void InsertAt(Interface* ptr, int index);
	void RemoveAt(int index);
	void display();
	void AddNameClass(std::string name);
	void Serialize(const char* path);
	void Deserialize(const char* path);

	~binary_tree();
};

