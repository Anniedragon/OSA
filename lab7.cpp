#include <iostream>
#include <fstream>

using namespace std;

const int N = 8; // Количество вершин в графе
int arr[N][N] = // Массив (матрица) смежности
{ {0,1,1,0,0,1,1,1},
{1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,1},
{0,0,0,0,1,1,0,0},
{0,0,0,1,0,1,1,1},
{1,0,0,1,1,0,0,0},
{1,0,0,0,1,0,0,0},
{1,1,1,0,1,0,0,0} };

bool visited[N]; // Массив пройденных вершин

int ways[N]; // Массив родительских вершин (VON_PUNKT)

struct item { // Структура элемента
    int data;
    item* next;
    item* prev;
};

class queue {
private:
    item* first; // Адрес первого элемента в списке
    item* last; // Адрес последнего элемента в списке
    int count; // Количество элементов в списке
    int VON_PUNKT[N];
    int k;
public:

    queue() {
        last = NULL;
        first = NULL;
        count = 0;
    }

    void add(int a) { // Добавление элемента в конец списка (push_fifo)
        item* newitem = new item;
        newitem->data = a;
        if (first == NULL) {
            first = newitem;
        }
        newitem->next = NULL;
        newitem->prev = last;
        if (last != NULL) {
            last->next = newitem;
        }
        last = newitem;
        count++;
    }

    void del_first() { // Удаление элемента из начала очереди (pop_fifo)
        item* place = first;
        if (place != last) { // Если элемент первый, но НЕ последний
            place->next->prev = NULL;
            first = place->next;
        }
        else { // Если элемент первый и последний
            first = NULL;
            last = NULL;
        }
        delete place;
        count--;
    }

    bool empty() { // Возвращает true если очередь пустая и false если нет
        bool empt;
        if (first == NULL) {
            empt = true;
        }
        else empt = false;
        return empt;
    }

    int first_data() { //Возвращает значение из начала очереди
        return first->data;
    }

    void search_in_width() {
        int start = 0;
        for (int i = 0; i < N; i++) {
            visited[i] = 0;
        }
        cout << "Из какой вершины начинается путь? ";
        cin >> start;
        add(start); // заносим в очередь начальную вершину
        visited[start] = 1; // отмечаем вершину, как посещённую
        ways[start] = -1; // определяем начало маршрута из начальной вершины в конечную 
        while (!empty()) { // пока очередь не пуста
            int unit = first_data(); // извлекаем 1ый элемент из очереди
            del_first(); // удаляем 1ый элемент их очереди
            for (int i = 0; i < N; i++) { // идём по всем вершинам графа
                if ((visited[i] == 0) && (arr[unit][i] == 1)) { // если вершина не посещена и имеется связь
                    add(i); // добавляем в очередь вершину i
                    ways[i] = unit; // запоминаем, из какой вершины мы пришли
                    visited[i] = 1; // помечаем вершину i, как пройденную
                }
            }
        }
        int end;
        cout << "До какой точки рассчитать маршрут? ";
        cin >> end; // определяем конечную вершину
        int dne = end; // запоминаем конечную вершину
        int count = 0; // создаем счётчик
        do { // делаем, пока не придём в начало маршрута
            count++; // увеличиваем счётчик на 1
            dne = ways[dne]; // запоминаем конечную вершину из маршрута
        } while (dne != ways[start]); 
        k = count;
        int* rev = new int[count];
        int i = 0; 
        rev[i] = end; // в первый элемент кладем конечную вершину
        i++; 
        do { // делаем, пока конечная вершина не будет равна начальной 
            rev[i] = ways[end]; // записываем маршрут
            i++;
            end = ways[end]; // запоминаем конечную вершину из посещенных
        } while (end != start);
        i--;
        cout << "Путь: ";
        while (i >= 0) {
            cout << rev[i] << " "; // выводим обновленный путь 
            i--;
        }
        cout << '\n';
        for (int i = 0; i < k; i++) {
            VON_PUNKT[i] = rev[i];
        }
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
        file << "Маршрут: " << endl;
        for (int i = k - 1; i >= 0; i--) {
            file << VON_PUNKT[i] << " ";
        }
        file.close();
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    queue Que;
    Que.search_in_width();
    Que.write_in_file();
    return 0;
}
