#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct bin_node { // узел бинарного дерева (вершина)
    int data; // число
    bin_node* left; // левое поддерево
    bin_node* right; // правое поддерево
};

struct bin_tree { // само бинарное дерево
    int count; // количество узлов (вершин)
    bin_node* root; // корень бинарного дерева
};

class Bin_Tree {
private:
    bin_tree* tree = new bin_tree;
public:
    Bin_Tree() { // конструктор (он же метод по созданию бинарного дерева)
        tree->root = NULL;
        tree->count = 0;
    } 

    int bin_search(int element) { // поиск узла дерева
        bin_node* node = new bin_node;
        if (tree == NULL) {
            cout << "Tree is empty" << endl;
            return 0;
        }
        node = tree->root;
        for (;;) {
            if (node == NULL) {
                return 0;
            }
            else if (node->data == element) {
                cout << "You element is found!" << endl;
                return 1;
            }
            else if (element > node->data) {
                node = node->right;
            }
            else node = node->left;
        }
    }

    int bin_insert(int element) { // вставка узла дерева
        bin_node* node = new bin_node;
        bin_node** addr_node = new bin_node*;
        node = tree->root;
        addr_node = &tree->root;
        for (;;) {
            if (node == NULL) {
                bin_node* n_node = new bin_node;
                n_node->data = element;
                n_node->left = n_node->right = NULL;
                *addr_node = n_node;
                tree->count++;
                return 1;
            }
            else if (node->data == element) {
                return 2;
            }
            else if (node->data < element) {
                addr_node = &node->right;
                node = node->right;
            }
            else {
                addr_node = &node->left;
                node = node->left;
            }
        }
    }

    bin_node* return_root() { // возврат адреса корня дерева
        return tree->root;
    }

    int tree_in_file(bin_node* node) { // запись дерева в файл
        if (node == NULL) {
            return 0;
        }
        ofstream file("C:\\Users\\agush\\Desktop\\Мосполитех. Программирование\\2 курс\\Основы современных алгоритмов\\test.txt", ofstream::app);
        file << node->data << " ";
        file.close();
        tree_in_file(node->right);
        tree_in_file(node->left);
    }
};
int main() {
    Bin_Tree tr;
    int element = 0;
    int array[] = { 14, 6, 20, 1, 29, 8, 20, 19, 7, 91, 51, 2, 31, 10 };
    for (int i = 0; i < 14; i++) {
        tr.bin_insert(array[i]);
    }
    cout << "Enter element that you want to find: ";
    cin >> element;
    tr.bin_search(element);
    tr.tree_in_file(tr.return_root());
    return 0;
}



