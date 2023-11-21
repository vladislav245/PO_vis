#include <queue>
#include "binary_tree.h"



std::vector<std::string> storage;





//в insertAt находим путь и создаем его 
//в binary_tree проходим по этому пути и делаем вставку элемента
void binary_tree::class_ptr::find_path(int ind, string* path) {


	int two = 1; //все элементы на этом уровне
	int all = 0; //все элементы дерева до этого уровня (не включительно)
	int lvl = 0; //итоговый уровень
	//ищем ее уровень
	while (two + all < (ind + 1)) {
		all += two;
		two *= 2;
		lvl++;
	}

	int step = 0;

	while (ind > 0) {

		if (ind % 2 == 0) *path += "R";
		else *path += "L";
		//необходимый сдвиг
		if (ind % 2 == 0) --ind;

		//1
		//N - кол-во элементов правее данного элемента на этой строке
		int N = (ind - (pow(2, lvl) - 1)) / 2;
		//2
		//номер след. элемента, который ссылался на наше число
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
				ptr->left = new class_ptr(obj, index);
				//ptr->left->left = nullptr;
				//ptr->left->right = nullptr;
				//ptr->left->obj = obj;
			}
			else if (ptr->left != nullptr && (it + 1) == path.end()) ptr->left->obj = obj;
			ptr = ptr->left;
		}
		else {
			if (ptr->right == nullptr && (it + 1) != path.end()) return;
			else if (ptr->right == nullptr && (it + 1) == path.end()) {
				ptr->right = new class_ptr(obj, index);
				/*ptr->right->left = nullptr;
				ptr->right->right = nullptr;
				ptr->right->obj = obj;*/
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
	ind = 0;
}

binary_tree::class_ptr::class_ptr(Interface* obj, int index) {
	this->obj = obj;
	ind = index;
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


void binary_tree::AddNameClass(std::string name) {
	storage.push_back(name);
}


void binary_tree::Serialize(const char* path) {

	if (cl_ptr == nullptr) return;

	std::fstream f(path, 'w');

	bool used[100]{ false };
	queue<class_ptr*> q;
	q.push(cl_ptr);
	used[0] = true;

	while (!q.empty()) {
		class_ptr* ptr = q.front();  //извлекаем из очереди текущую вершину
		q.pop();

		if (find(storage.begin(), storage.end(), ptr->obj->Name()) != storage.end()) {
			f << ptr->obj->Name() << '\n';
			f << ptr->ind << '\n';
			ptr->obj->Serialize(f);
			//ptr = ptr->Get_Next();
		}

		//добавляем всех непосещённых соседей
		if(ptr->left != nullptr) { 
			if (!used[ptr->left->ind]) {
				q.push(ptr->left);
				used[ptr->left->ind] = true;
			}
		}
		if (ptr->right != nullptr) {
			if (!used[ptr->right->ind]) {
				q.push(ptr->right);
				used[ptr->right->ind] = true;
			}
		}

	}
	f.close();
}


void binary_tree::Deserialize(const char* path) {


	std::fstream f(path);
	Interface* tmp = nullptr;
	
	while (!f.eof()) {

		char buffer[256];
		int index = 0;

		//проблема с вводом
		//после первого объекта ничего не вводит
		f >> buffer;
		f >> index;

		if (find(storage.begin(), storage.end(), buffer) != storage.end()) {
			if (strcmp(buffer, "Employee") == 0) tmp = new Employee;
			else if (strcmp(buffer, "Self_Employeed") == 0) tmp = new Self_Employeed(0);
			else if (strcmp(buffer, "Businessman") == 0) tmp = new Businessman("word", 0);
			else if (strcmp(buffer, "Translator") == 0) tmp = new Translator("lolka");
			else continue;

			tmp->Deserialize(f);
			InsertAt(tmp, index);
		}
	}
	f.close();
}