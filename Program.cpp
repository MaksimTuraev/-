#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

struct point {
    int x;
    int y;
    string s;

    // Оператор сравнения для порядка сортировки
    bool operator<(const point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

// Оператор ввода для структуры point
istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y >> p.s;
    return is;
}

// Оператор вывода для структуры point
ostream& operator<<(ostream& os, const point& p) {
    os << p.x << " " << p.y << " " << p.s;
    return os;
}

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    // Чтение данных из файла
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    vector<point> V;
    copy(istream_iterator<point>(inFile), istream_iterator<point>(), back_inserter(V));
    inFile.close();

    // Сортировка с сохранением порядка элементов с одинаковыми ключами
    stable_sort(V.begin(), V.end());

    // Запись отсортированных данных обратно в файл
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return 1;
    }

    copy(V.begin(), V.end(), ostream_iterator<point>(outFile, "\n"));
    outFile.close();

    cout << "File " << filename << " has been sorted successfully." << endl;
    return 0;
}
