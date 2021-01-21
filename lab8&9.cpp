#include <iostream>
#include <fstream>
using namespace std;

const int N = 8;

int arr[N][N] = //Массив смежности
{ {0,1,1,0,0,1,1,1},
{1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,1},
{0,0,0,0,1,1,0,0},
{0,0,0,1,0,1,1,1},
{1,0,0,1,1,0,0,0},
{1,0,0,0,1,0,0,0},
{1,1,1,0,1,0,0,0} };

struct item {
	int data;
	item* next;
	item* prev;
};

class Stack {
private:
	item* top;
	int count;
	int k;
	bool visited[N];
	int ways[N]; //родительский массив
	int VON_PUNKT[N]; // массив маршрута
public:
	Stack() {
		top = NULL;
		count = 0;
	}

	void push_lifo(int a) {
		item* newitem = new item;
		newitem->data = a;
		newitem->next = top;
		top = newitem;
		count++;
	}

	bool empty() {
		bool empt;
		if (top == NULL)
			empt = true;
		else
			empt = false;
		return empt;
	}

	void del() {
		item* place = top;
		if (place->next != NULL)
		{
			place->next->prev = NULL;
			top = place->next;
		}
		else top = NULL;
		delete place;
	}

	int pop_lifo() {
		int temp = top->data;
		del();
		return temp;
	}

	void out(int s_el, int en_el) {
		int dne = en_el;
		int count = 0;
		do {
			count++;
			dne = ways[dne];
		} while (dne != ways[s_el]);
		k = count;
		int* rev = new int[count]; // массив маршрута
		int i = 0;
		rev[i] = en_el; // конечный элемент - первый
		i++;
		do {
			rev[i] = ways[en_el]; // записываем элемент из массива родительских вершин
			i++;
			en_el = ways[en_el];
		} while (en_el != s_el);
		i--;
		while (i >= 0) { // запись с конца
			cout << rev[i] << " ";
			i--;
		}
		for (int i = 0; i < k; i++) {
			VON_PUNKT[i] = rev[i];
		}
	}

	void search_in_depth() {
		int start, end;
		for (int i = 0; i < N; i++)
		{
			visited[i] = 0;
		}
		cout << "Из какой вершины начинается путь? ";
		cin >> start;
		push_lifo(start);
		cout << "До какой точки рассчитать маршрут? ";
		cin >> end;
		visited[start] = true;
		ways[start] = -1;
		while (!empty()) {
			int unit = pop_lifo(); // извлекаем элемент
			for (int i = 0; i < N; i++) {
				if ((visited[i] == 0) && (arr[unit][i] == 1)) {
					push_lifo(i);
					ways[i] = unit; // записываем родительскую вершину
					visited[i] = true;
				}
			}
		}
		out(start, end);
	}

	void write_in_file() {
		ofstream file("C:\\Users\\agush\\Desktop\\Мосполитех. Программирование\\search", ofstream::app);
		file << "Матрица смежности:" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				file << arr[i][j] << " ";
			}
			file << endl;
		}
		file << "Маршрут (через стек): " << endl;
		for (int i = k - 1; i >= 0; i--) {
			file << VON_PUNKT[i] << " ";
		}
		file.close();
	}
};

class rec {
private:
	bool visited[N]; //Массив пройденных вершин
	int ways[N]; //Массив родительских вершин
	int VON_PUNKT[N]; // массив маршрута
	int k;
public:
	void func(int dot) {
		for (int i = 0; i < N; i++) {
			if (!visited[i] && arr[dot][i] == 1) {
				ways[i] = dot;
				visited[i] = true;
				func(i);
			}
		}
	}

	void search() {
		int start;
		for (int i = 0; i < N; i++) {
			visited[i] = false;
		}
		cout << endl;
		cout << "\nВведите начальную точку (нумерация с 0): ";
		cin >> start;
		visited[start] = true;
		ways[start] = -1;
		func(start);
		int end;
		cout << "До какой точки рассчитать маршрут(нумерация с 0): ";
		cin >> end;
		int dne = end;
		int count = 0;
		do {
			count++;
			dne = ways[dne];
		} while (dne != ways[start]);
		k = count;
		int* rev = new int[count];
		int i = 0;
		rev[i] = end;
		i++;
		do {
			rev[i] = ways[end];
			i++;
			end = ways[end];
		} while (end != start);
		i--;
		cout << "Путь: ";
		while (i >= 0)
		{
			cout << rev[i] << " ";
			i--;
		}
		cout << '\n';
		for (int i = 0; i < k; i++) {
			VON_PUNKT[i] = rev[i];
		}
	}

	void write_in_file() {
		ofstream file("C:\\Users\\agush\\Desktop\\Мосполитех. Программирование\\search", ofstream::app);
		file << "\nМаршрут (через рекурсию): " << endl;
		for (int i = k - 1; i >= 0; i--) {
			file << VON_PUNKT[i] << " ";
		}
		file.close();
	}
};

int main() {
	setlocale(LC_ALL, "");
	Stack st;
	rec r;
	st.search_in_depth();
	r.search();
	st.write_in_file();
	r.write_in_file();
	return 0;
}
