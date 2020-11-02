#include <iostream>
using namespace std;
struct student {
	string name;
	string recbook_num;
	string fac;
	string groupe;
};
struct node {
	int data;
	node* next;
};
class List {
private:
	node* first;
public:
	List() {
		first->next = NULL;
	}
	void add_to_end(int d) {
		if (first->next == NULL) {
			node* current = new node;
			current->data = d;
			first->next = current;
			current->next = NULL;
		 }
	}
	void show_list() {
		node* current = first;
		while (current != NULL) {
			cout << endl << current->data;
			current = current->next;
		}
	}
	void add_to_begin(int d) {
		node* new_element = new node;
		new_element->data = d;
		new_element->next = first;
		first = new_element;
	}
	void delete_the_last() {

	}
	void delete_the_first() {

	}
	void search_element() {

	}
	void add_after_found() {

	}
	void delete_found() {

	}
};
int main() {
	List li;
	li.add_to_end(25);
	li.add_to_end(36);
	li.add_to_end(49);
	li.add_to_end(64);
	li.show_list();
	cout << endl;
	return 0;
}
