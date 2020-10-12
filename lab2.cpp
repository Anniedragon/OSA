#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct student {
	int flag = 0;
	string name;
	string recbook_num;
	string fac;
	string groupe;
};
const int N = 5;
class Data_base {
private:
	student array[N];
public:
	void empty_element(int index) { 
		if (array[index].flag == 0) {
			cout << "Clear!" << endl;
		}
		else {
			array[index].name = "";
			array[index].recbook_num = "";
			array[index].fac = "";
			array[index].groupe = "";
			array[index].flag = 0;
		}
	}
	void free_struct_var() { 
		for (int i = 0; i < N; i++) {
			if (array[i].flag == 0) {
				cout << i << " place is free" << endl;
				break;
			}
		}
	}
	void input_struct_var(int index, student s) {
		array[index].flag = 1;
		array[index].name = s.name;
		array[index].recbook_num = s.recbook_num;
		array[index].fac = s.fac;
		array[index].groupe = s.groupe;
	}
	void output_struct_var(int index) {
		cout << "Name: " << array[index].name << endl
			<< "Record book number: " << array[index].recbook_num << endl
			<< "Faculty: " << array[index].fac << endl
			<< "Groupe: " << array[index].groupe << endl;
	}
	void output_all() {
		for (int i = 0; i < N; i++) {
			if (array[i].flag == 1) {
				cout << "Name: " << array[i].name << endl
					<< "Record book number: " << array[i].recbook_num << endl
					<< "Faculty: " << array[i].fac << endl
					<< "Groupe: " << array[i].groupe << endl << "\n";
			}
			else break;
		}
	}
	void search_element(int field, string element) {
		int count = 0;
		int max = 0;
		string maxstr;
		switch (field) {
		case 0: // name
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < (array[i].name).size(); j++) {
					if (element[j] == array[i].name[j]) {
						count++;
					}
				}
				if (count > max) {
					max = count;
					maxstr = array[i].name;
				}
				count = 0;
			}
			break;
		case 1: // recbook_num
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < (array[i].recbook_num).size(); j++) {
					if (element[j] == array[i].recbook_num[j]) {
						count++;
					}
				}
				if (count > max) {
					max = count;
					maxstr = array[i].recbook_num;
				}
				count = 0;
			}
			break;
		case 2: // fac
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < (array[i].fac).size(); j++) {
					if (element[j] == array[i].fac[j]) {
						count++;
					}
				}
				if (count > max) {
					max = count;
					maxstr = array[i].fac;
				}
				count = 0;
			}
			break;
		case 3: // groupe
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < (array[i].groupe).size(); j++) {
					if (element[j] == array[i].groupe[j]) {
						count++;
					}
				}
				if (count > max) {
					max = count;
					maxstr = array[i].groupe;
				}
				count = 0;
			}
			break;
		default:
			cout << "This field is absent. Try again." << endl;
			break;
		}
		cout << "Equal or the closest element: " << maxstr << endl;
	}
	void search_min_element(int field) {
		string min;
		switch (field) {
		case 0: // name
			min = array[0].name;
			for (int i = 0; i < N - 1; i++) {
				if (min < array[i + 1].name) {
					min = array[i + 1].name;
				}
			}
			break;
		case 1: // recbook_num
			min = array[0].recbook_num;
			for (int i = 0; i < N - 1; i++) {
				if (min < array[i + 1].recbook_num) {
					min = array[i + 1].recbook_num;
				}
			}
			break;
		case 2: // fac
			min = array[0].fac;
			for (int i = 0; i < N - 1; i++) {
				if (min < array[i + 1].fac) {
					min = array[i + 1].fac;
				}
			}
			break;
		case 3: // groupe
			min = array[0].groupe;
			for (int i = 0; i < N - 1; i++) {
				if (min < array[i + 1].groupe) {
					min = array[i + 1].groupe;
				}
			}
			break;
		default:
			cout << "This field is absent. Try again." << endl;
			break;
		}
		cout << "The minimal element is: " << min << endl;
	}
	void sort_min_to_max(int field) { // В Ы В О Д  Н Е  Р А Б О Т А Е Т
		Data_base db;
		student temp;
		switch (field) {
		case 0: // name
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (array[i].name < array[j].name) {
						temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}
			}
			break;
		case 1: // recbook_num
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (array[i].recbook_num < array[j].recbook_num) {
						temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}
			}
			break;
		case 2: // fac
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (array[i].fac < array[j].fac) {
						temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}
			}
			break;
		case 3: // groupe
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (array[i].groupe < array[j].groupe) {
						temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}
			}
			break;
			db.output_all();
		default:
			cout << "This field is absent. Try again." << endl;
			break;
		}
	}
	void sort_max_to_min(int field) { // В Ы В О Д  Н Е  Р А Б О Т А Е Т
		Data_base db;
		student temp;
		switch (field) {
		case 0: // name
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (array[i].name > array[j].name) {
						temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}
			}
			break;
		case 1: // recbook_num
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (array[i].recbook_num > array[j].recbook_num) {
						temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}
			}
			break;
		case 2: // fac
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (array[i].fac > array[j].fac) {
						temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}
			}
			break;
		case 3: // groupe
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (array[i].groupe > array[j].groupe) {
						temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}
			}
			break;
			db.output_all();
		default:
			cout << "This field is absent. Try again." << endl;
			break;
		}
	}
	void write_in_file() {
		string tr = "\n";
		ofstream file("C:\\Users\\agush\\Desktop\\Мосполитех. Программирование\\data_base");
		for (int i = 0; i < N; i++) {
			file << array[i].name + tr;
			file << array[i].recbook_num + tr;
			file << array[i].fac + tr;
			file << array[i].groupe + tr;
			file << endl;
		}
		file.close();
		cout << "Check file data_base.txt" << endl;
	}
	void read_from_file() {
		string line;
		ifstream file("C:\\Users\\agush\\Desktop\\Мосполитех. Программирование\\data_base");
		while (getline(file, line)) {
			cout << line << endl;
		}
	}
	void file_clear() { // extra method
		ofstream file("C:\\Users\\agush\\Desktop\\Мосполитех. Программирование\\data_base");
		file.write("", 0);
		file.close();
		cout << "Check file data_base.txt" << endl;
	}
};
int main() {
	Data_base db;
	student array[N];
	student st;
	int index = 0;
	int field = 0;
	string element;
	db.empty_element(index);
	db.free_struct_var();
	for (int i = 0; i < N; i++) {
		cout << "Enter information about " << i + 1 << " student." << endl
			<< "Enter name like Familia_IO: ";
		cin >> st.name;
		cout << "Enter the record book number: ";
		cin >> st.recbook_num;
		cout << "Enter the faculty name: ";
		cin >> st.fac;
		cout << "Enter the groupe number: ";
		cin >> st.groupe;
		db.input_struct_var(i, st);
	}
	cout << "Enter index: ";
	cin >> index;
	db.output_struct_var(index);
	db.output_all();
	cout << "Seach element" << endl;
	cout << "Enter field: 0 - name, 1 - record book number, 2 - faculty, 3 - groupe" << endl;
	cin >> field;
	cout << "Enter element, that you want to find: ";
	cin >> element;
	db.search_element(field, element);
	cout << "Minimal element" << endl;
	cout << "Enter field: 0 - name, 1 - record book number, 2 - faculty, 3 - groupe" << endl;
	cin >> field;
	db.search_min_element(field);
	cout << "Min to max sort" << endl;
	cout << "Enter field: 0 - name, 1 - record book number, 2 - faculty, 3 - groupe" << endl;
	cin >> field;
	db.sort_min_to_max(field);
	cout << "Max to min sort" << endl;
	cout << "Enter field: 0 - name, 1 - record book number, 2 - faculty, 3 - groupe" << endl;
	cin >> field;
	db.sort_max_to_min(field);
	db.write_in_file();
	db.read_from_file();
	db.file_clear();
	return 0;
}
