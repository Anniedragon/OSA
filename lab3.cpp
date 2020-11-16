#include <iostream>
#include <string>
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
	node* first = new node;
	node* last = new node;
public:
	List() {
		first->next = last;
		last->next = NULL;
	}
	void add_to_end(int d) {
		node* current = new node;
		last->next = current;
		last->data = d;
		last = current;
		last->next = NULL;
	}
	void show_list() {
		node* current = first->next;
		while (current->next != NULL) {
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
		node* current = new node;
		current = first;
		while (current->next->next != NULL) {
			current = current->next;
		}
		current->next = NULL;
		last = current;
	}
	void delete_the_first() {
		first->next = first->next->next;
	}
	void search_element(int elem) {
		node* current = new node;
		current = first->next;
		while (current->next != NULL) {
			if (current->data == elem) {
				cout << current->data << endl;
				break;
			}
			else current = current->next;
		}
	}
	void add_after_found(int elem, int temp1) {
		int cur1, cur2;
		node* current = new node;
		current = first->next;
		while (current->next != NULL) {
			if (current->data == elem) {
				if (current->next == NULL) {
					last->data = temp1;
					add_to_end(NULL);
				}
				else if (current->next->next == NULL) {
					last->data = current->next->data;
					add_to_end(NULL);
					current->next->data = temp1;
				}
				else if (current->next->next->next == NULL) {
					last->data = current->next->next->data;
					current->next->next->data = current->next->data;
					add_to_end(NULL);
					current->next->data = temp1;
				}
				else {
					cur1 = current->next->data;
					cur2 = current->next->next->data;
					while (current->next != NULL) {
						current->next->next->data = cur1;
						cur1 = cur2;
						cur2 = current->next->next->next->data;
						current = current->next;
						if (current->next->next->next == NULL) {
							break;
						}
					}
				}
			}
			else current = current->next;
		}
		add_to_end(NULL);
		current = first->next;
		while (current->next != NULL) {
			if (current->data == elem) {
				current->next->data = temp1;
				break;
			}
		}
		show_list();
	}
	void delete_found(int elem) {
		int cur1 = 0;
		node* current = new node;
		current = first->next;
		while (current->next != NULL) {
			if (current->data == elem) {
				cur1 = current->next->data;
				current->data = cur1;
				//cur1 = current->next->next->data;
				current = current->next;
			}
			else current = current->next;
		}
		show_list();
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
	//li.delete_the_last();
	//li.show_list();
	//li.add_to_end(64);
	//cout << endl;
	int temp = 0;
	//cout << "Search element" << endl;
	//cout << "Enter number: ";
	//cin >> temp;
	//li.search_element(temp);
	int temp1 = 0;
	int temp2 = 0;
	//cout << "Add after found" << endl;
	//cout << "Enter element and new element: ";
	//cin >> temp1 >> temp2;
	//li.add_after_found(temp1, temp2);
	cout << "Delete found" << endl;
	cout << "Enter element: ";
	cin >> temp1;
	li.delete_found(temp1);
	return 0;
}
