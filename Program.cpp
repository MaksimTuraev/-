#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>

int main() {
    // Пример набора чисел с четным количеством элементов
    std::deque<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Заполняем дек D с использованием итераторов (аналог `ptin_iterator`)
    std::deque<int> D(numbers.begin(), numbers.end());

    // Вычисляем середину дека
    size_t half = D.size() / 2;

    // Выводим первую половину в обратном порядке
    std::copy(
        std::make_reverse_iterator(D.begin() + half),  // от середины до начала
        D.rend(),                                      // конец первой половины
        std::ostream_iterator<int>(std::cout, " ")     // вывод в консоль
    );

    // Выводим вторую половину в обратном порядке
    std::copy(
        std::make_reverse_iterator(D.end()),           // от конца до середины
        std::make_reverse_iterator(D.begin() + half),  // конец второй половины
        std::ostream_iterator<int>(std::cout, " ")     // вывод в консоль
    );

    std::cout << std::endl;

    return 0;
}
