#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    cout << "Enter an even number of integers (end with Ctrl+D/Ctrl+Z): ";

    // Чтение чисел с помощью istream_iterator в дек
    deque<int> D((istream_iterator<int>(cin)), istream_iterator<int>());

    if (D.size() % 2 != 0) {
        cerr << "Error: The number of elements must be even!" << endl;
        return 1;
    }

    // Вывод первой половины в обратном порядке
    cout << "First half (reversed): ";
    copy(D.rbegin() + D.size() / 2, D.rend(), ostream_iterator<int>(cout, " "));

    // Вывод второй половины в обратном порядке
    cout << "\nSecond half (reversed): ";
    copy(D.rbegin(), D.rbegin() + D.size() / 2, ostream_iterator<int>(cout, " "));

    cout << endl;
    return 0;
}
