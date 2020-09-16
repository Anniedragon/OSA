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
