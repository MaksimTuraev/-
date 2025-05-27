using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        // Исходный набор целых чисел с четным количеством элементов
        int[] numbers = { 1, 2, 3, 4, 5, 6, 7, 8 };

        // Проверяем, что количество элементов четное
        if (numbers.Length % 2 != 0)
        {
            Console.WriteLine("Количество элементов должно быть четным.");
            return;
        }

        // Заполняем дек D исходными числами
        LinkedList<int> deque = new LinkedList<int>(numbers);

        // Определяем середину дека
        int mid = deque.Count / 2;

        // Разделяем дек на две половины
        var firstHalf = deque.Take(mid).Reverse(); // Первая половина в обратном порядке
        var secondHalf = deque.Skip(mid).Take(mid).Reverse(); // Вторая половина в обратном порядке

        // Выводим первую половину в обратном порядке
        Console.WriteLine("Первая половина в обратном порядке:");
        foreach (var item in firstHalf)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();

        // Выводим вторую половину в обратном порядке
        Console.WriteLine("Вторая половина в обратном порядке:");
        foreach (var item in secondHalf)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();
    }
}