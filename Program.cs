#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    // Ввод вектора V0
    cout << "Enter elements of vector V0 (end with Ctrl+D/Ctrl+Z): ";
    vector<int> V0((istream_iterator<int>(cin)), istream_iterator<int>());
    cin.clear(); // Сброс флага EOF после ввода V0

    // Ввод числа N
    int N;
    cout << "Enter N (>0): ";
    cin >> N;
    if (N <= 0) {
        cerr << "Error: N must be positive!" << endl;
        return 1;
    }

    // Ввод векторов V1, ..., VN
    vector<vector<int>> VI(N);
    for (int i = 0; i < N; ++i) {
        cout << "Enter elements of vector V" << i+1 << " (end with Ctrl+D/Ctrl+Z): ";
        VI[i].assign(istream_iterator<int>(cin), istream_iterator<int>());
        cin.clear();
    }

    // Создание множества из V0 (убираем дубликаты)
    set<int> setV0(V0.begin(), V0.end());

    // Подсчет векторов, содержащих все элементы V0
    int count = 0;
    for (const auto& vec : VI) {
        set<int> setVI(vec.begin(), vec.end());
        if (includes(setVI.begin(), setVI.end(), setV0.begin(), setV0.end())) {
            ++count;
        }
    }

    // Вывод результата
    cout << "Number of vectors containing all elements of V0: " << count << endl;

    return 0;
}
