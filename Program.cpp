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
    
    // Конструктор по умолчанию
    point() : x(0), y(0) {}
    
    // Конструктор с параметрами
    point(int x_val, int y_val, const string& str) : x(x_val), y(y_val), s(str) {}
    
    // Оператор сравнения для отношения порядка
    bool operator<(const point& other) const {
        if (x < other.x) return true;
        if (x == other.x && y < other.y) return true;
        return false;
    }
};

// Оператор ввода
istream& operator>>(istream& is, point& p) {
    return is >> p.x >> p.y >> p.s;
}

// Оператор вывода
ostream& operator<<(ostream& os, const point& p) {
    return os << p.x << " " << p.y << " " << p.s;
}

int main() {
    const string filename = "points.txt"; // Имя файла
    
    // Чтение данных из файла
    ifstream in_file(filename);
    if (!in_file) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return 1;
    }
    
    vector<point> V;
    
    // Использование istream_iterator для заполнения вектора
    copy(istream_iterator<point>(in_file), 
         istream_iterator<point>(), 
         back_inserter(V));
    
    in_file.close();
    
    // Проверка на пустой файл
    if (V.empty()) {
        cout << "Файл пуст!" << endl;
        return 0;
    }
    
    // Устойчивая сортировка с использованием заданного отношения порядка
    stable_sort(V.begin(), V.end());
    
    // Запись отсортированных данных обратно в файл
    ofstream out_file(filename);
    if (!out_file) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return 1;
    }
    
    // Использование ostream_iterator для записи в файл
    copy(V.begin(), V.end(), 
         ostream_iterator<point>(out_file, "\n"));
    
    out_file.close();
    
    cout << "Файл успешно отсортирован! Обработано " 
         << V.size() << " точек." << endl;
    
    return 0;
}
