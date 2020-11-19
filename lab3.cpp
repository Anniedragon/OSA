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
	student data;
	node* next;
};

struct node_duo {
	student data;
	node_duo* next;
	node_duo* previous;
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

	void show_list() {
		node* current = first->next;
		int k = 1;
		cout << "List" << endl;
		while (current->next != NULL) {
			cout << k << endl;
			cout << "Name: " << current->data.name << endl
				<< "Record book number: " << current->data.recbook_num << endl
				<< "Faculty: " << current->data.fac << endl
				<< "Groupe: " << current->data.groupe << "\n" << endl;
			current = current->next;
			k++;
		}
	}

	void show_list_2() {
		node* current = first->next;
		int k = 1;
		cout << "List" << endl;
		while (current->next->next != NULL) {
			cout << k << endl;
			cout << "Name: " << current->data.name << endl
				<< "Record book number: " << current->data.recbook_num << endl
				<< "Faculty: " << current->data.fac << endl
				<< "Groupe: " << current->data.groupe << "\n" << endl;
			current = current->next;
			k++;
		}
	}

	void add_to_end(student d) {
		node* current = new node;
		last->next = current;
		last->data = d;
		last = current;
		last->next = NULL;
	}

	void add_to_begin(student d) {
		node* current = new node;
		current->data = d;
		current->next = first;
		first = current;
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

	void search_element(int field, string elem) {
		node* current = new node;
		current = first->next;
		switch (field) {
		case 0:
			while (current->next != NULL) {
				if (current->data.name == elem) {
					cout << current->data.name << endl;
					break;
				}
				else current = current->next;
			}
			break;
		case 1:
			while (current->next != NULL) {
				if (current->data.recbook_num == elem) {
					cout << current->data.recbook_num << endl;
					break;
				}
				else current = current->next;
			}
			break;
		case 2:
			while (current->next != NULL) {
				if (current->data.fac == elem) {
					cout << current->data.fac << endl;
					break;
				}
				else current = current->next;
			}
			break;
		case 3:
			while (current->next != NULL) {
				if (current->data.groupe == elem) {
					cout << current->data.groupe << endl;
					break;
				}
				else current = current->next;
			}
			break;
		default:
			cout << "Your field is empty. Try again." << endl;
			break;
		}
	}

	void add_after_found(int field, string elem, student new_elem) {
		student st;
		string n1, n2, r1, r2, f1, f2, g1, g2;
		node* current = new node;
		current = first->next;
		switch (field) {
		case 0:
			while (current->next != NULL) {
				if (current->data.name == elem) {
					if (current->next == NULL) {
						add_to_end(new_elem);
						break;
					}
					else if (current->next->next == NULL) {
						add_to_end(current->next->data);
						current->next->data = new_elem;
					}
					else if (current->next->next->next == NULL) {
						add_to_end(current->next->next->data);
						current->next->next->data = current->next->data;
						current->next->data = new_elem;
					}
					else {
						n1 = current->next->data.name;
						n2 = current->next->next->data.name;
						r1 = current->next->data.recbook_num;
						r2 = current->next->next->data.recbook_num;
						f1 = current->next->data.fac;
						f2 = current->next->next->data.fac;
						g1 = current->next->data.groupe;
						g2 = current->next->next->data.groupe;
						while (current->next != NULL) {
							current->next->next->data.name = n1;
							n1 = n2;
							n2 = current->next->next->next->data.name;
							current->next->next->data.recbook_num = r1;
							r1 = r2;
							r2 = current->next->next->next->data.recbook_num;
							current->next->next->data.fac = f1;
							f1 = f2;
							f2 = current->next->next->next->data.fac;
							current->next->next->data.groupe = g1;
							g1 = g2;
							g2 = current->next->next->next->data.groupe;
							current = current->next;
							if (current->next->next->next == NULL) {
								st.name = n1;
								st.recbook_num = r1;
								st.fac = f1;
								st.groupe = g1;
								add_to_end(st);
								break;
							}
						}
					}
				}
				else current = current->next;
			}
			current = first->next;
			while (current->next != NULL) {
				if (current->data.name == elem) {
					current->next->data = new_elem;
					break;
				}
				else current = current->next;
			}
			show_list();
			break;
		case 1:
			while (current->next != NULL) {
				if (current->data.recbook_num == elem) {
					if (current->next == NULL) {
						add_to_end(new_elem);
						break;
					}
					else if (current->next->next == NULL) {
						add_to_end(current->next->data);
						current->next->data = new_elem;
					}
					else if (current->next->next->next == NULL) {
						add_to_end(current->next->next->data);
						current->next->next->data = current->next->data;
						current->next->data = new_elem;
					}
					else {
						n1 = current->next->data.name;
						n2 = current->next->next->data.name;
						r1 = current->next->data.recbook_num;
						r2 = current->next->next->data.recbook_num;
						f1 = current->next->data.fac;
						f2 = current->next->next->data.fac;
						g1 = current->next->data.groupe;
						g2 = current->next->next->data.groupe;
						while (current->next != NULL) {
							current->next->next->data.name = n1;
							n1 = n2;
							n2 = current->next->next->next->data.name;
							current->next->next->data.recbook_num = r1;
							r1 = r2;
							r2 = current->next->next->next->data.recbook_num;
							current->next->next->data.fac = f1;
							f1 = f2;
							f2 = current->next->next->next->data.fac;
							current->next->next->data.groupe = g1;
							g1 = g2;
							g2 = current->next->next->next->data.groupe;
							current = current->next;
							if (current->next->next->next == NULL) {
								st.name = n1;
								st.recbook_num = r1;
								st.fac = f1;
								st.groupe = g1;
								add_to_end(st);
								break;
							}
						}
					}
				}
				else current = current->next;
			}
			current = first->next;
			while (current->next != NULL) {
				if (current->data.recbook_num == elem) {
					current->next->data = new_elem;
					break;
				}
				else current = current->next;
			}
			show_list();
			break;
		case 2:
			while (current->next != NULL) {
				if (current->data.fac == elem) {
					if (current->next == NULL) {
						add_to_end(new_elem);
						break;
					}
					else if (current->next->next == NULL) {
						add_to_end(current->next->data);
						current->next->data = new_elem;
					}
					else if (current->next->next->next == NULL) {
						add_to_end(current->next->next->data);
						current->next->next->data = current->next->data;
						current->next->data = new_elem;
					}
					else {
						n1 = current->next->data.name;
						n2 = current->next->next->data.name;
						r1 = current->next->data.recbook_num;
						r2 = current->next->next->data.recbook_num;
						f1 = current->next->data.fac;
						f2 = current->next->next->data.fac;
						g1 = current->next->data.groupe;
						g2 = current->next->next->data.groupe;
						while (current->next != NULL) {
							current->next->next->data.name = n1;
							n1 = n2;
							n2 = current->next->next->next->data.name;
							current->next->next->data.recbook_num = r1;
							r1 = r2;
							r2 = current->next->next->next->data.recbook_num;
							current->next->next->data.fac = f1;
							f1 = f2;
							f2 = current->next->next->next->data.fac;
							current->next->next->data.groupe = g1;
							g1 = g2;
							g2 = current->next->next->next->data.groupe;
							current = current->next;
							if (current->next->next->next == NULL) {
								st.name = n1;
								st.recbook_num = r1;
								st.fac = f1;
								st.groupe = g1;
								add_to_end(st);
								break;
							}
						}
					}
				}
				else current = current->next;
			}
			current = first->next;
			while (current->next != NULL) {
				if (current->data.fac == elem) {
					current->next->data = new_elem;
					break;
				}
				else current = current->next;
			}
			show_list();
			break;
		case 3:
			while (current->next != NULL) {
				if (current->data.groupe == elem) {
					if (current->next == NULL) {
						add_to_end(new_elem);
						break;
					}
					else if (current->next->next == NULL) {
						add_to_end(current->next->data);
						current->next->data = new_elem;
					}
					else if (current->next->next->next == NULL) {
						add_to_end(current->next->next->data);
						current->next->next->data = current->next->data;
						current->next->data = new_elem;
					}
					else {
						n1 = current->next->data.name;
						n2 = current->next->next->data.name;
						r1 = current->next->data.recbook_num;
						r2 = current->next->next->data.recbook_num;
						f1 = current->next->data.fac;
						f2 = current->next->next->data.fac;
						g1 = current->next->data.groupe;
						g2 = current->next->next->data.groupe;
						while (current->next != NULL) {
							current->next->next->data.name = n1;
							n1 = n2;
							n2 = current->next->next->next->data.name;
							current->next->next->data.recbook_num = r1;
							r1 = r2;
							r2 = current->next->next->next->data.recbook_num;
							current->next->next->data.fac = f1;
							f1 = f2;
							f2 = current->next->next->next->data.fac;
							current->next->next->data.groupe = g1;
							g1 = g2;
							g2 = current->next->next->next->data.groupe;
							current = current->next;
							if (current->next->next->next == NULL) {
								st.name = n1;
								st.recbook_num = r1;
								st.fac = f1;
								st.groupe = g1;
								add_to_end(st);
								break;
							}
						}
					}
				}
				else current = current->next;
			}
			current = first->next;
			while (current->next != NULL) {
				if (current->data.groupe == elem) {
					current->next->data = new_elem;
					break;
				}
				else current = current->next;
			}
			show_list();
			break;
		default:
			cout << "Your field is empty. Try again." << endl;
			break;
		}		
	}

	void delete_found(int field, string elem) {
		string cur1;
		int flag = 0;
		node* current = new node;
		current = first->next;
		switch (field) {
		case 0:
			while (current->next != NULL) {
				if (current->data.name == elem) {
					cur1 = current->next->data.name;
					current->data.name = cur1;
					cur1 = current->next->data.recbook_num;
					current->data.recbook_num = cur1;
					cur1 = current->next->data.fac;
					current->data.fac = cur1;
					cur1 = current->next->data.groupe;
					current->data.groupe = cur1;
					current = current->next;
					flag = 1;
				}
				else {
					if (flag == 1) {
						cur1 = current->next->data.name;
						current->data.name = cur1;
						cur1 = current->next->data.recbook_num;
						current->data.recbook_num = cur1;
						cur1 = current->next->data.fac;
						current->data.fac = cur1;
						cur1 = current->next->data.groupe;
						current->data.groupe = cur1;
						current = current->next;
					}
					else current = current->next;
				}
			} 
			show_list_2();
			break;
		case 1:
			while (current->next != NULL) {
				if (current->data.recbook_num == elem) {
					cur1 = current->next->data.name;
					current->data.name = cur1;
					cur1 = current->next->data.recbook_num;
					current->data.recbook_num = cur1;
					cur1 = current->next->data.fac;
					current->data.fac = cur1;
					cur1 = current->next->data.groupe;
					current->data.groupe = cur1;
					current = current->next;
					flag = 1;
				}
				else {
					if (flag == 1) {
						cur1 = current->next->data.name;
						current->data.name = cur1;
						cur1 = current->next->data.recbook_num;
						current->data.recbook_num = cur1;
						cur1 = current->next->data.fac;
						current->data.fac = cur1;
						cur1 = current->next->data.groupe;
						current->data.groupe = cur1;
						current = current->next;
					}
					else current = current->next;
				}
			}
			show_list_2();
			break;
		case 2:
			while (current->next != NULL) {
				if (current->data.fac == elem) {
					cur1 = current->next->data.name;
					current->data.name = cur1;
					cur1 = current->next->data.recbook_num;
					current->data.recbook_num = cur1;
					cur1 = current->next->data.fac;
					current->data.fac = cur1;
					cur1 = current->next->data.groupe;
					current->data.groupe = cur1;
					current = current->next;
					flag = 1;
				}
				else {
					if (flag == 1) {
						cur1 = current->next->data.name;
						current->data.name = cur1;
						cur1 = current->next->data.recbook_num;
						current->data.recbook_num = cur1;
						cur1 = current->next->data.fac;
						current->data.fac = cur1;
						cur1 = current->next->data.groupe;
						current->data.groupe = cur1;
						current = current->next;
					}
					else current = current->next;
				}
			}
			show_list_2();
			break;
		case 3:
			while (current->next != NULL) {
				if (current->data.groupe == elem) {
					cur1 = current->next->data.name;
					current->data.name = cur1;
					cur1 = current->next->data.recbook_num;
					current->data.recbook_num = cur1;
					cur1 = current->next->data.fac;
					current->data.fac = cur1;
					cur1 = current->next->data.groupe;
					current->data.groupe = cur1;
					current = current->next;
					flag = 1;
				}
				else {
					if (flag == 1) {
						cur1 = current->next->data.name;
						current->data.name = cur1;
						cur1 = current->next->data.recbook_num;
						current->data.recbook_num = cur1;
						cur1 = current->next->data.fac;
						current->data.fac = cur1;
						cur1 = current->next->data.groupe;
						current->data.groupe = cur1;
						current = current->next;
					}
					else current = current->next;
				}
			}
			show_list_2();
			break;
		default:
			cout << "Your field is empty. Try again." << endl;
			break;
		}		
	}
};

class List_duo {
private:
	node_duo* first = new node_duo;
	node_duo* last = new node_duo;
public:
	List_duo() {
		first->next = last;
		last->previous = first;
		first->previous = NULL;
		last->next = NULL;
	}

	void show_list() {
		node_duo* current = first->next;
		int k = 1;
		cout << "List duo" << endl;
		while (current->next != NULL) {
			cout << k << endl;
			cout << "Name: " << current->data.name << endl
				<< "Record book number: " << current->data.recbook_num << endl
				<< "Faculty: " << current->data.fac << endl
				<< "Groupe: " << current->data.groupe << "\n" << endl;
			current = current->next;
			k++;
		}
	}

	void show_list_2() {
		node_duo* current = first->next;
		int k = 1;
		cout << "List duo" << endl;
		while (current->next->next != NULL) {
			cout << k << endl;
			cout << "Name: " << current->data.name << endl
				<< "Record book number: " << current->data.recbook_num << endl
				<< "Faculty: " << current->data.fac << endl
				<< "Groupe: " << current->data.groupe << "\n" << endl;
			current = current->next;
			k++;
		}
	}

	void add_to_end(student d) {
		node_duo* current = new node_duo;
		last->next = current;
		last->data = d;
		last = current;
		last->next = NULL;
	}

	void add_to_begin(student d) {
		node_duo* current = new node_duo;
		current->data = d;
		current->next = first;
		first = current;
	}
	
	void delete_the_last() {
		node_duo* current = new node_duo;
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

	void search_element(int field, string elem) {
		node_duo* current = new node_duo;
		current = first->next;
		switch (field) {
		case 0:
			while (current->next != NULL) {
				if (current->data.name == elem) {
					cout << current->data.name << endl;
					break;
				}
				else current = current->next;
			}
			break;
		case 1:
			while (current->next != NULL) {
				if (current->data.recbook_num == elem) {
					cout << current->data.recbook_num << endl;
					break;
				}
				else current = current->next;
			}
			break;
		case 2:
			while (current->next != NULL) {
				if (current->data.fac == elem) {
					cout << current->data.fac << endl;
					break;
				}
				else current = current->next;
			}
			break;
		case 3:
			while (current->next != NULL) {
				if (current->data.groupe == elem) {
					cout << current->data.groupe << endl;
					break;
				}
				else current = current->next;
			}
			break;
		default:
			cout << "Your field is empty. Try again." << endl;
			break;
		}
	}

	void add_after_found(int field, string elem, student new_elem) {
		student st;
		string n1, n2, r1, r2, f1, f2, g1, g2;
		node_duo* current = new node_duo;
		current = first->next;
		switch (field) {
		case 0:
			while (current->next != NULL) {
				if (current->data.name == elem) {
					if (current->next == NULL) {
						add_to_end(new_elem);
						break;
					}
					else if (current->next->next == NULL) {
						add_to_end(current->next->data);
						current->next->data = new_elem;
					}
					else if (current->next->next->next == NULL) {
						add_to_end(current->next->next->data);
						current->next->next->data = current->next->data;
						current->next->data = new_elem;
					}
					else {
						n1 = current->next->data.name;
						n2 = current->next->next->data.name;
						r1 = current->next->data.recbook_num;
						r2 = current->next->next->data.recbook_num;
						f1 = current->next->data.fac;
						f2 = current->next->next->data.fac;
						g1 = current->next->data.groupe;
						g2 = current->next->next->data.groupe;
						while (current->next != NULL) {
							current->next->next->data.name = n1;
							n1 = n2;
							n2 = current->next->next->next->data.name;
							current->next->next->data.recbook_num = r1;
							r1 = r2;
							r2 = current->next->next->next->data.recbook_num;
							current->next->next->data.fac = f1;
							f1 = f2;
							f2 = current->next->next->next->data.fac;
							current->next->next->data.groupe = g1;
							g1 = g2;
							g2 = current->next->next->next->data.groupe;
							current = current->next;
							if (current->next->next->next == NULL) {
								st.name = n1;
								st.recbook_num = r1;
								st.fac = f1;
								st.groupe = g1;
								add_to_end(st);
								break;
							}
						}
					}
				}
				else current = current->next;
			}
			current = first->next;
			while (current->next != NULL) {
				if (current->data.name == elem) {
					current->next->data = new_elem;
					break;
				}
				else current = current->next;
			}
			show_list();
			break;
		case 1:
			while (current->next != NULL) {
				if (current->data.recbook_num == elem) {
					if (current->next == NULL) {
						add_to_end(new_elem);
						break;
					}
					else if (current->next->next == NULL) {
						add_to_end(current->next->data);
						current->next->data = new_elem;
					}
					else if (current->next->next->next == NULL) {
						add_to_end(current->next->next->data);
						current->next->next->data = current->next->data;
						current->next->data = new_elem;
					}
					else {
						n1 = current->next->data.name;
						n2 = current->next->next->data.name;
						r1 = current->next->data.recbook_num;
						r2 = current->next->next->data.recbook_num;
						f1 = current->next->data.fac;
						f2 = current->next->next->data.fac;
						g1 = current->next->data.groupe;
						g2 = current->next->next->data.groupe;
						while (current->next != NULL) {
							current->next->next->data.name = n1;
							n1 = n2;
							n2 = current->next->next->next->data.name;
							current->next->next->data.recbook_num = r1;
							r1 = r2;
							r2 = current->next->next->next->data.recbook_num;
							current->next->next->data.fac = f1;
							f1 = f2;
							f2 = current->next->next->next->data.fac;
							current->next->next->data.groupe = g1;
							g1 = g2;
							g2 = current->next->next->next->data.groupe;
							current = current->next;
							if (current->next->next->next == NULL) {
								st.name = n1;
								st.recbook_num = r1;
								st.fac = f1;
								st.groupe = g1;
								add_to_end(st);
								break;
							}
						}
					}
				}
				else current = current->next;
			}
			current = first->next;
			while (current->next != NULL) {
				if (current->data.recbook_num == elem) {
					current->next->data = new_elem;
					break;
				}
				else current = current->next;
			}
			show_list();
			break;
		case 2:
			while (current->next != NULL) {
				if (current->data.fac == elem) {
					if (current->next == NULL) {
						add_to_end(new_elem);
						break;
					}
					else if (current->next->next == NULL) {
						add_to_end(current->next->data);
						current->next->data = new_elem;
					}
					else if (current->next->next->next == NULL) {
						add_to_end(current->next->next->data);
						current->next->next->data = current->next->data;
						current->next->data = new_elem;
					}
					else {
						n1 = current->next->data.name;
						n2 = current->next->next->data.name;
						r1 = current->next->data.recbook_num;
						r2 = current->next->next->data.recbook_num;
						f1 = current->next->data.fac;
						f2 = current->next->next->data.fac;
						g1 = current->next->data.groupe;
						g2 = current->next->next->data.groupe;
						while (current->next != NULL) {
							current->next->next->data.name = n1;
							n1 = n2;
							n2 = current->next->next->next->data.name;
							current->next->next->data.recbook_num = r1;
							r1 = r2;
							r2 = current->next->next->next->data.recbook_num;
							current->next->next->data.fac = f1;
							f1 = f2;
							f2 = current->next->next->next->data.fac;
							current->next->next->data.groupe = g1;
							g1 = g2;
							g2 = current->next->next->next->data.groupe;
							current = current->next;
							if (current->next->next->next == NULL) {
								st.name = n1;
								st.recbook_num = r1;
								st.fac = f1;
								st.groupe = g1;
								add_to_end(st);
								break;
							}
						}
					}
				}
				else current = current->next;
			}
			current = first->next;
			while (current->next != NULL) {
				if (current->data.fac == elem) {
					current->next->data = new_elem;
					break;
				}
				else current = current->next;
			}
			show_list();
			break;
		case 3:
			while (current->next != NULL) {
				if (current->data.groupe == elem) {
					if (current->next == NULL) {
						add_to_end(new_elem);
						break;
					}
					else if (current->next->next == NULL) {
						add_to_end(current->next->data);
						current->next->data = new_elem;
					}
					else if (current->next->next->next == NULL) {
						add_to_end(current->next->next->data);
						current->next->next->data = current->next->data;
						current->next->data = new_elem;
					}
					else {
						n1 = current->next->data.name;
						n2 = current->next->next->data.name;
						r1 = current->next->data.recbook_num;
						r2 = current->next->next->data.recbook_num;
						f1 = current->next->data.fac;
						f2 = current->next->next->data.fac;
						g1 = current->next->data.groupe;
						g2 = current->next->next->data.groupe;
						while (current->next != NULL) {
							current->next->next->data.name = n1;
							n1 = n2;
							n2 = current->next->next->next->data.name;
							current->next->next->data.recbook_num = r1;
							r1 = r2;
							r2 = current->next->next->next->data.recbook_num;
							current->next->next->data.fac = f1;
							f1 = f2;
							f2 = current->next->next->next->data.fac;
							current->next->next->data.groupe = g1;
							g1 = g2;
							g2 = current->next->next->next->data.groupe;
							current = current->next;
							if (current->next->next->next == NULL) {
								st.name = n1;
								st.recbook_num = r1;
								st.fac = f1;
								st.groupe = g1;
								add_to_end(st);
								break;
							}
						}
					}
				}
				else current = current->next;
			}
			current = first->next;
			while (current->next != NULL) {
				if (current->data.groupe == elem) {
					current->next->data = new_elem;
					break;
				}
				else current = current->next;
			}
			show_list();
			break;
		default:
			cout << "Your field is empty. Try again." << endl;
			break;
		}
	}

	void delete_found(int field, string elem) {
		string cur1;
		int flag = 0;
		node_duo* current = new node_duo;
		current = first->next;
		switch (field) {
		case 0:
			while (current->next != NULL) {
				if (current->data.name == elem) {
					cur1 = current->next->data.name;
					current->data.name = cur1;
					cur1 = current->next->data.recbook_num;
					current->data.recbook_num = cur1;
					cur1 = current->next->data.fac;
					current->data.fac = cur1;
					cur1 = current->next->data.groupe;
					current->data.groupe = cur1;
					current = current->next;
					flag = 1;
				}
				else {
					if (flag == 1) {
						cur1 = current->next->data.name;
						current->data.name = cur1;
						cur1 = current->next->data.recbook_num;
						current->data.recbook_num = cur1;
						cur1 = current->next->data.fac;
						current->data.fac = cur1;
						cur1 = current->next->data.groupe;
						current->data.groupe = cur1;
						current = current->next;
					}
					else current = current->next;
				}
			}
			show_list_2();
			break;
		case 1:
			while (current->next != NULL) {
				if (current->data.recbook_num == elem) {
					cur1 = current->next->data.name;
					current->data.name = cur1;
					cur1 = current->next->data.recbook_num;
					current->data.recbook_num = cur1;
					cur1 = current->next->data.fac;
					current->data.fac = cur1;
					cur1 = current->next->data.groupe;
					current->data.groupe = cur1;
					current = current->next;
					flag = 1;
				}
				else {
					if (flag == 1) {
						cur1 = current->next->data.name;
						current->data.name = cur1;
						cur1 = current->next->data.recbook_num;
						current->data.recbook_num = cur1;
						cur1 = current->next->data.fac;
						current->data.fac = cur1;
						cur1 = current->next->data.groupe;
						current->data.groupe = cur1;
						current = current->next;
					}
					else current = current->next;
				}
			}
			show_list_2();
			break;
		case 2:
			while (current->next != NULL) {
				if (current->data.fac == elem) {
					cur1 = current->next->data.name;
					current->data.name = cur1;
					cur1 = current->next->data.recbook_num;
					current->data.recbook_num = cur1;
					cur1 = current->next->data.fac;
					current->data.fac = cur1;
					cur1 = current->next->data.groupe;
					current->data.groupe = cur1;
					current = current->next;
					flag = 1;
				}
				else {
					if (flag == 1) {
						cur1 = current->next->data.name;
						current->data.name = cur1;
						cur1 = current->next->data.recbook_num;
						current->data.recbook_num = cur1;
						cur1 = current->next->data.fac;
						current->data.fac = cur1;
						cur1 = current->next->data.groupe;
						current->data.groupe = cur1;
						current = current->next;
					}
					else current = current->next;
				}
			}
			show_list_2();
			break;
		case 3:
			while (current->next != NULL) {
				if (current->data.groupe == elem) {
					cur1 = current->next->data.name;
					current->data.name = cur1;
					cur1 = current->next->data.recbook_num;
					current->data.recbook_num = cur1;
					cur1 = current->next->data.fac;
					current->data.fac = cur1;
					cur1 = current->next->data.groupe;
					current->data.groupe = cur1;
					current = current->next;
					flag = 1;
				}
				else {
					if (flag == 1) {
						cur1 = current->next->data.name;
						current->data.name = cur1;
						cur1 = current->next->data.recbook_num;
						current->data.recbook_num = cur1;
						cur1 = current->next->data.fac;
						current->data.fac = cur1;
						cur1 = current->next->data.groupe;
						current->data.groupe = cur1;
						current = current->next;
					}
					else current = current->next;
				}
			}
			show_list_2();
			break;
		default:
			cout << "Your field is empty. Try again." << endl;
			break;
		}
	}
};

int main() {
	List l1; // односвязный список
	List_duo l2; // двусвязный список
	int flag;
	student st = {"P_VV", "456", "I", "6"}; // 1
	l1.add_to_end(st);
	l2.add_to_end(st);
	st = { "U_GU", "902", "K", "2" }; // 2
	l1.add_to_end(st);
	l2.add_to_end(st);
	st = { "J_FT", "451", "L", "1" }; // 3
	l1.add_to_end(st);
	l2.add_to_end(st);
	st = { "H_IO", "561", "F", "8" }; // 4
	l1.add_to_end(st);
	l2.add_to_end(st);
	st = { "V_YY", "501", "R", "3" }; // 5
	l1.add_to_end(st);
	l2.add_to_end(st);
	st = { "B_SR", "390", "X", "4" }; // 6
	l1.add_to_end(st);
	l2.add_to_end(st);

	l1.show_list();
	l2.show_list();

	cout << "\nDelete element" << endl;
	cout << "Where do you want to delete element? end - 0, begin - 1: ";
	cin >> flag;
	while ((flag != 0) && (flag != 1)) {
		cout << "Enter 0 or 1: ";
		cin >> flag;
	}
	if (flag == 0) {
		l1.delete_the_last();
		l2.delete_the_last();
	}
	else {
		l1.delete_the_first();
		l2.delete_the_first();
	}
	l1.show_list();
	l2.show_list();

	int field;
	string element;
	cout << "\nSearch element" << endl;
	cout << "Enter the field, 0 - name, 1 - record book number, 2 - faculty, 3 - groupe: ";
	cin >> field;
	cout << "Enter element: ";
	cin >> element;
	cout << "List" << endl;
	l1.search_element(field, element);
	cout << "List duo" << endl;
	l2.search_element(field, element);

	cout << "\nAdd after found" << endl; 
	student new_element;
	cout << "Enter the field, 0 - name, 1 - record book number, 2 - faculty, 3 - groupe: ";
	cin >> field;
	cout << "Enter element: ";
	cin >> element;
	new_element = { "N_MM", "777", "M", "10" };
	l1.add_after_found(field, element, new_element);
	l2.add_after_found(field, element, new_element);

	cout << "\nDelete found" << endl;
	cout << "Enter the field, 0 - name, 1 - record book number, 2 - faculty, 3 - groupe: ";
	cin >> field;
	cout << "Enter element: ";
	cin >> element;
	l1.delete_found(field, element);
	l2.delete_found(field, element);
	return 0;
}


