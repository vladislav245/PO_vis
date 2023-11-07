#include <queue>
#include "binary_tree.h"

//в insertAt находим путь и создаем его 
//в binary_tree проходим по этому пути и делаем вставку элемента

void binary_tree::class_ptr::find_path(int ind, string* path) {
	
	
	int two = 1;
	int s = 0;
	int lvl = 0;
	//ищем ее уровень
	while (two + s < (ind + 1)) {
		s += two;
		two *= 2;
		lvl++;
	}
	
	int step = 0;

	while (ind > 0) {

		if (ind % 2 == 0) *path += "R";
		else *path += "L";
		
		if (ind % 2 == 0) --ind;

		//1
		int N = (ind - (pow(2, lvl) - 1)) / 2;
		//2
		ind -= ((N * 2) + (pow(2, lvl - 1) - N));


		step++;
		lvl--;
	}

	reverse(path->begin(), path->end());
}

void binary_tree::InsertAt(Interface* obj, int index) {

	if (index == 0) {
		if (cl_ptr == nullptr) cl_ptr = new class_ptr;
		cl_ptr->obj = obj;
		return;
	}

	string path;
	cl_ptr->find_path(index, &path);
	class_ptr* ptr = cl_ptr;

	for (auto it = path.begin(); it != path.end(); ++it) {
		
		if (*it == 'L') {
			if (ptr->left == nullptr && (it + 1) != path.end()) return;
			else if (ptr->left == nullptr && (it + 1) == path.end()) {
				ptr->left = new class_ptr;
				ptr->left->left = nullptr;
				ptr->left->right = nullptr;
				ptr->left->obj = obj;
			}
			else if(ptr->left != nullptr && (it + 1) == path.end()) ptr->left->obj = obj;
			ptr = ptr->left;
		}
		else {
			if (ptr->right == nullptr && (it + 1) != path.end()) return;
			else if (ptr->right == nullptr && (it + 1) == path.end()) {
				ptr->right = new class_ptr;
				ptr->right->left = nullptr;
				ptr->right->right = nullptr;
				ptr->right->obj = obj;
			}
			else if (ptr->right != nullptr && (it + 1) == path.end()) ptr->right->obj = obj;

			ptr = ptr->right;
		}
	}
}

void binary_tree::RemoveAt(int index) {

	class_ptr* ptr = cl_ptr;
	class_ptr* next = ptr;
	if (index != 0) {

		string path;
		cl_ptr->find_path(index, &path);

		for (auto it = path.begin(); it != path.end(); ++it) {
			if (*it == 'L') {
				if (ptr->left == nullptr && (it + 1) != path.end()) return;
				else if (ptr->left == nullptr && (it + 1) == path.end()) {
					return;
				}
				else if (ptr->left != nullptr && (it + 1) == path.end()) {
					next = ptr->left;
					break;
				}
				ptr = ptr->left;
			}
			else {
				if (ptr->right == nullptr && (it + 1) != path.end()) return;
				else if (ptr->right == nullptr && (it + 1) == path.end()) {
					return;
				}
				else if (ptr->right != nullptr && (it + 1) == path.end()) {
					next = ptr->right;
					break;
				}

				ptr = ptr->right;
			}

		}
	}

	if (next->left == nullptr && next->right == nullptr) {
		if (ptr->left == next) ptr->left = nullptr;
		else if (ptr->right == next) ptr->right = nullptr;
		delete next;
	}
	else if (next->left != nullptr && next->right != nullptr) {
		class_ptr* tmp = next;
		class_ptr* next_tmp;
		while (tmp->left != nullptr || tmp->right != nullptr) {
			if (tmp->right != nullptr) {
				if (tmp->right->left == nullptr && tmp->right->right == nullptr) {
					next_tmp = tmp;
					tmp = tmp->right;
					next_tmp->right = nullptr;
					break;
				}
				tmp = tmp->right;
			}
			if (tmp->left != nullptr) {
				if (tmp->left->left == nullptr && tmp->left->right == nullptr) {
					next_tmp = tmp;
					tmp = tmp->left;
					next_tmp->left = nullptr;
					break;
				}
				tmp = tmp->left;
			}
		}
		next->obj = tmp->obj;
	}
	else if (next->left != nullptr || next->right != nullptr) {
		if (next->left != nullptr) {
			next->obj = next->left->obj;
			next->right = next->left->right;
			next->left = next->left->left;
		}
		else if (next->right != nullptr) {
			next->obj = next->right->obj;
			next->left = next->right->left;
			next->right = next->right->right;
		}
	}
}

binary_tree::~binary_tree() {
	if (cl_ptr != nullptr) 
	{
		if (cl_ptr->left != nullptr) delete cl_ptr->left;
		if (cl_ptr->right != nullptr) delete cl_ptr->right;
		delete cl_ptr;
	}
}

binary_tree::class_ptr::class_ptr() {
	obj = nullptr;
	left = nullptr;
	right = nullptr;
}

binary_tree::class_ptr::class_ptr(Interface* obj, int index) {
	this->obj = obj;
	left = nullptr;
	right = nullptr;
}

void binary_tree::display_tree(class_ptr* tree, int space, char direction) {

	if (tree->left != nullptr) {
		display_tree(tree->left, space + 2, 'L');
	}

	if (tree->right != nullptr) {
		display_tree(tree->right, space + 2, 'R');
	}

	char tab[2] = " ";
	printf("%*s#%c\n", space, tab, direction);
	tree->obj->Output();
	printf("\n");
}

void binary_tree::display() {
	display_tree(cl_ptr, 0, 'H');
}