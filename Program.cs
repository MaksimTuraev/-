using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        // Пример данных
        List<int> V0 = new List<int> { 1, 2, 3 }; // Вектор V0
        List<List<int>> vectors = new List<List<int>> // Набор векторов V1, ..., VN
        {
            new List<int> { 1, 2, 3, 4 },
            new List<int> { 2, 3, 5 },
            new List<int> { 1, 2, 3 },
            new List<int> { 1, 4, 5 }
        };

        int N = vectors.Count; // Количество векторов
        int count = 0; // Счетчик подходящих векторов

        // Преобразуем V0 в множество (для исключения повторений)
        HashSet<int> setV0 = new HashSet<int>(V0);

        // Перебираем каждый вектор из набора
        for (int i = 0; i < N; i++)
        {
            // Преобразуем текущий вектор в множество
            HashSet<int> setVi = new HashSet<int>(vectors[i]);

            // Проверяем, содержатся ли все элементы setV0 в setVi
            if (setV0.IsSubsetOf(setVi))
            {
                count++; // Увеличиваем счетчик, если условие выполняется
            }
        }

        // Вывод результата
        Console.WriteLine($"Количество векторов, содержащих все элементы V0: {count}");
    }
}
