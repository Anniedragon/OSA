//stack

#include <iostream>
using namespace std;
int N = 10;
class Stack {
private:
	int* arr;
	int top;
public:
	Stack() {
		top = -1;
		arr = new int[N];
	}
	Stack(int m) {
		top = -1;
		arr = new int[m];
	}
	~Stack() {
		delete[] arr;
	}
	void push(int a) {
		if (top == N - 1) {
			cout << "Stack is overflow!" << endl;
		}
		else {
			top++;
			arr[top] = a;
		}
	}
	void pop() {
		if (top >= 0) {
			cout << arr[top];
			top--;
		}
		else cout << "Stack is empty!";
	}
};
int main() {
	int znach;
	bool r;
	cout << "How much elements will be in stack? - ";
	cin >> N;
	Stack one(N);
	do {
		cout << "Enter 1 to add element or enter 0 to get out: ";
		cin >> r;
		if (r) {
			cout << "Enter element: ";
			cin >> znach;
			one.push(znach);
		}
		else {
			cout << "Element is: ";
			one.pop();
			cout << endl;
		}
	} while (true);
	return 0;
}

//queue

#include <iostream>
using namespace std;
int N = 10;
class Queue {
private:
	int* arr;
	int head;
	int tail;
public:
	Queue() {
		head = 0;
		tail = 0;
		arr = new int[N];
	}
	Queue(int m) {
		head = 0;
		tail = 0;
		arr = new int[m];
	}
	~Queue() {
		delete[] arr;
	}
	void add_item(int a) {
		if (head == (tail + 1) % N) {
			cout << "Queue is overfloated!" << endl;
		}
		else {
			arr[tail] = a;
			tail = (tail + 1) % N;
		}
	}
	void extract_item() {
		if (head != tail) {
			cout << arr[head];
			head = (head + 1) % N;
		}
		else cout << "Queue is empty!";
	}
};
int main() {
	int znach;
	bool r;
	cout << "How many elements will be in queue? - ";
	cin >> N;
	Queue one(N);
	do {
		cout << "Enter 1 to add or enter 0 to get out: ";
		cin >> r;
		if (r) {
			cout << "Enter element: ";
			cin >> znach;
			one.add_item(znach);
		}
		else {
			cout << "Element is: ";
			one.extract_item();
			cout << endl;
		}
	} while (true);
	return 0;
}
