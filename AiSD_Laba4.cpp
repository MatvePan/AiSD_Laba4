#include "iostream"
using namespace std;

struct Tree {
	int leaf;
	Tree* left;
	Tree* right;

	Tree(int currleaf) {
		leaf = currleaf;
		left = nullptr;
		right = nullptr;
	}
};

Tree* paste(Tree* root, int cleaf) {
	if (root == nullptr)
		return new Tree(cleaf);
	if (cleaf < root->leaf)
		root->left = paste(root->left, cleaf);
	else if (cleaf > root->leaf)
		root->right = paste(root->right, cleaf);
	return root;
}

void tring(Tree* root) { // Прямой обход
	if (root == nullptr)
		return;
	cout << root->leaf << "-";
	tring(root->left);
	tring(root->right);
}

void eturn(Tree* root) { // Обратный обход
	if (root == nullptr)
		return;
	eturn(root->left);
	eturn(root->right);
	cout << root->leaf << "-";
}

void simm(Tree* root) { // Симметричный обход
	if (root == nullptr)
		return;
	simm(root->left);
	cout << root->leaf << "-";
	simm(root->right);
}

void enter(Tree* &root) {
	int number;
	cout << "\nВводите элементы\n";
	cout << "Для конца ввода введите 0\n";
	while (cin >> number and number != 0)
		root = paste(root, number);
}

void build(Tree* &oak) {
	cout << "Прямой обход:\n";
	tring(oak);
	cout << "\n\nОбратный обход:\n";
	eturn(oak);
	cout << "\n\nСимметричный обход:\n";
	simm(oak);
	cout << "\n";
}

int main() {
	setlocale(LC_ALL, "RUS");
	Tree* oak = nullptr;
	while (true) {
		int mode;
		cout << "\n";
		cout << "1. Ввод элементов множества\n";
		cout << "2. Вывод бинарного дерева\n";
		cout << "0. Выход\n";
		cout << "Введите число для выбора\n";
		cin >> mode;
		switch (mode) {
		case 1:
			enter(oak);
			break;
		case 2:
			if (oak == nullptr)
				cout << "Дерева нет\n";
			else
				build(oak);
			break;
		case 0:
			return 0;
		default:
			cout << "Неверный ввод\n";
		}
	}
}