#include <iostream>
#include <fstream>
using namespace std;

const int N = 5;

class Deykstra_alg {
private:
    int FIKS[N]; // посещённые вершины (v)
    int MIN_WEG[N]; // минимальное расстояние (d)
    int VON_PUNKT[N]; // минимальный маршрут до конечной вершиной (ver)
    int DUG[N][N]; // матрица расстояний (a)
    int temp, minindex, min;
    int start = 0;
    int end;
    int k, fk;
public:
    void get_data() { // инициализация
        for (int i = 0; i < N; i++) { // заполнение матрицы расстояний
            DUG[i][i] = 0;
            for (int j = i + 1; j < N; j++) {
                cout << "Введите расстояние " << i + 1 << " - " << j + 1 << " : ";
                cin >> temp;
                DUG[i][j] = DUG[j][i] = temp;
            }
        }
        cout << endl;
        for (int i = 0; i < N; i++) { // вывод матрицы расстояний 
            for (int j = 0; j < N; j++) {
                cout << DUG[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < N; i++) { // инициализация вершин и расстояний 
            MIN_WEG[i] = 10000;
            FIKS[i] = 0;
            VON_PUNKT[i] = -1;
        }
    }


    void deykstra_alg() {
        MIN_WEG[start] = 0;
        // Шаг алгоритма
        do {
            minindex = 10000;
            min = 10000;
            for (int i = 0; i < N; i++) { 
                if ((FIKS[i] == 0) && (MIN_WEG[i] < min)) { // если вершину ещё не обошли и вес меньше min
                    min = MIN_WEG[i]; // Переприсваиваем значения
                    minindex = i;
                }
            }
            // Добавляем найденный минимальный вес к текущему весу вершины 
            // и сравниваем с текущим минимальным весом вершины
            if (minindex != 10000) {
                for (int i = 0; i < N; i++) {
                    if (DUG[minindex][i] > 0) {
                        temp = min + DUG[minindex][i];
                        if (temp < MIN_WEG[i]) {
                            MIN_WEG[i] = temp;
                        }
                    }
                }
                FIKS[minindex] = 1;
            }
        } while (minindex < 10000);
        cout << "Кратчайшие расстояния до вершин: " << endl;
        for (int i = 0; i < N; i++) {
            cout << MIN_WEG[i] << " ";
        }
        cout << endl << "\n";
        // восстановление пути
        // массив посещённых вершин VON_PUNKT[]
        end = 4; // индекс конечной вершины 4 (N = 5)
        VON_PUNKT[0] = end + 1; // начальный элемент - конечная вершина
        k = 1; // индекс предыдущей вершины
        int weight = MIN_WEG[end]; // вес конечной вершины
        while (end != start) { // пока не дошли до начальной вершины
            for (int i = 0; i < N; i++) { // просматриваем все вершины
                if (DUG[i][end] != 0) { // если есть связь
                    temp = weight - DUG[i][end]; // определяем вес пути из предыдущей вершины
                    if (temp == MIN_WEG[i]) { // если вес совпал с рассчитанным, значит из этой вершины и был переход
                        weight = temp; // сохраняем новый вес 
                        end = i; // сохраняем предыдущую вершину
                        VON_PUNKT[k] = i + 1; // записываем её в массив
                        k++;
                    }
                }
            }
        }
        fk = k;
        cout << "Вывод кратчайшего пути: " << endl;
        for (int i = k - 1; i >= 0; i--) {
            cout << VON_PUNKT[i] << " ";
        }
        cout << endl;
    }

    void write_in_file() {       
        ofstream file("C:\\Users\\agush\\Desktop\\Мосполитех. Программирование\\deykstra_file", ofstream::app); 
        file << "Матрица расстояний:" << endl ;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                file << DUG[i][j] << "\t";
            }
            file << endl;
        }
        file << "\nКратчайшие расстояния до вершин: " << endl;
        for (int i = 0; i < N; i++) {
            file << MIN_WEG[i] << " ";
        }
        file << endl;
        file << "\nВывод кратчайшего пути: " << endl;
        for (int i = fk - 1; i >= 0; i--) {
            file << VON_PUNKT[i] << " ";
        }
        file.close();
        cout << "\nИнформация занесена в файл" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Deykstra_alg d;
    d.get_data();
    d.deykstra_alg();
    d.write_in_file();
    return 0;
}
