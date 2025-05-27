using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        // Имена файлов
        string fileName1 = "name1.txt"; // Файл с исходными словами
        string fileName2 = "name2.txt"; // Файл с набором слов (и для записи результата)

        // Проверяем существование файлов
        if (!File.Exists(fileName1))
        {
            Console.WriteLine($"Файл {fileName1} не найден.");
            return;
        }

        if (!File.Exists(fileName2))
        {
            Console.WriteLine($"Файл {fileName2} не найден.");
            return;
        }

        // Читаем слова из файлов
        var words1 = File.ReadLines(fileName1).ToList(); // Слова из файла name1
        var words2 = File.ReadLines(fileName2).ToList(); // Слова из файла name2

        // Проверяем, что файлы не пустые
        if (words1.Count == 0 || words2.Count == 0)
        {
            Console.WriteLine("Один из файлов пуст.");
            return;
        }

        // Создаем результат, объединяя слова из двух файлов
        var result = words2
            .Zip(words1, (word2, word1) => $"{word2}-{word1}") // Объединяем слова с дефисом
            .ToList();

        // Записываем результат обратно в файл name2
        File.WriteAllLines(fileName2, result);

        Console.WriteLine($"Результат записан в файл {fileName2}.");
    }
}