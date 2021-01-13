#include <iostream>
using namespace std;

const int V = 8; //Количество вершин в графе

int arr[V][V] = //Массив смежности
{ {0,1,1,0,0,1,1,1},
{1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,1},
{0,0,0,0,1,1,0,0},
{0,0,0,1,0,1,1,0},
{1,0,0,1,1,0,0,0},
{1,0,0,0,1,0,0,0},
{1,1,1,0,1,0,0,0} };

class rec {
private:
    bool visited[V]; //Массив пройденных вершин
    int ways[V]; //Массив родительских вершин
public:
    void func(int dot) {
        for (int i = 0; i < V; i++) {
            if (!visited[i] && arr[dot][i] == 1) {
                ways[i] = dot;
                visited[i] = true;
                func(i);
            }
        }           
    }

    void search() {
        int start;
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }           
        cout << "Введите начальную точку (нумерация с 0): ";
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
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    rec r;
    r.search();
    return 0;
}
