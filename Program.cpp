#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    // Пример входных данных
    vector<int> V0 = {1, 2, 3};  // Вектор V0
    int N = 3;                    // Количество векторов V1, ..., VN
    vector<vector<int>> VN = {    // Векторы V1, ..., VN
        {1, 2, 3, 4, 5},         // V1: содержит все элементы V0
        {2, 3, 4},               // V2: не содержит 1 из V0
        {1, 3, 2, 5}             // V3: содержит все элементы V0 (порядок не важен)
    };

    // Преобразуем V0 в множество для удобства проверки (убираем дубли)
    set<int> setV0(V0.begin(), V0.end());

    int count = 0;  // Счетчик векторов, содержащих все элементы V0

    for (const auto& vi : VN) {
        // Преобразуем текущий вектор vi в множество
        set<int> setVI(vi.begin(), vi.end());

        // Проверяем, содержит ли setVI все элементы setV0
        if (includes(setVI.begin(), setVI.end(), setV0.begin(), setV0.end())) {
            count++;
        }
    }

    cout << "Количество векторов, содержащих все элементы V0: " << count << endl;

    return 0;
}
