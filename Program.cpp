#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

// Структура point
struct point {
    int x, y;
    string s;

    // Оператор < для отношения порядка
    bool operator<(const point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

// Оператор ввода (считывание из потока)
istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y >> p.s;
    return is;
}

// Оператор вывода (запись в поток)
ostream& operator<<(ostream& os, const point& p) {
    os << p.x << " " << p.y << " " << p.s;
    return os;
}

int main() {
    const string filename = "points.txt";  // Имя файла

    // Чтение данных из файла в вектор
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Не удалось открыть файл " << filename << endl;
        return 1;
    }

    vector<point> V;
    copy(
        istream_iterator<point>(inFile),
        istream_iterator<point>(),
        back_inserter(V)
    );
    inFile.close();

    // Сортировка вектора с сохранением порядка равных элементов
    stable_sort(V.begin(), V.end());

    // Запись отсортированных данных обратно в файл
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Не удалось открыть файл для записи " << filename << endl;
        return 1;
    }

    copy(
        V.begin(),
        V.end(),
        ostream_iterator<point>(outFile, "\n")
    );
    outFile.close();

    cout << "Файл успешно перезаписан с отсортированными данными." << endl;

    return 0;
}
