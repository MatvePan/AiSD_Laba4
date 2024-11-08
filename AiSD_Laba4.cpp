#include "iostream"
#include "vector"
using namespace std;

void Enter(vector<int>& mass) {

}

void Tree(vector<int>& mass) {

}

int main() {
	setlocale(LC_ALL, "RUS");
	vector<int> monzh;
	while (true) {
		int mode;
		cout << "1. Ввод элементов множества\n";
		cout << "2. Вывод бинарного дерева\n";
		cout << "0. Выход\n";
		cout << "Введите число для выбора\n";
		cin >> mode;
		switch (mode) {
		case 1:
			Enter(monzh);
			break;
		case 2:
			Tree(monzh);
			break;
		case 3:
			break;
		default:
			cout << "Неверный ввод\n";
		}
	}
}