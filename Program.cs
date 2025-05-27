using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

struct Point
{
    public int X { get; set; }
    public int Y { get; set; }
    public string S { get; set; }

    // Перегрузка оператора ввода
    public static Point Parse(string input)
    {
        var parts = input.Split(' ');
        if (parts.Length != 3)
            throw new FormatException("Invalid input format for Point.");

        return new Point
        {
            X = int.Parse(parts[0]),
            Y = int.Parse(parts[1]),
            S = parts[2]
        };
    }

    // Перегрузка оператора вывода
    public override string ToString()
    {
        return $"{X} {Y} {S}";
    }

    // Реализация отношения порядка
    public static bool operator <(Point a, Point b)
    {
        return a.X < b.X || (a.X == b.X && a.Y < b.Y);
    }

    public static bool operator >(Point a, Point b)
    {
        return !(a < b) && !(a.X == b.X && a.Y == b.Y);
    }
}

class Program
{
    static void Main(string[] args)
    {
        string fileName = "points.txt";

        // Чтение данных из файла
        List<Point> points;
        try
        {
            points = File.ReadAllLines(fileName)
                         .Select(Point.Parse)
                         .ToList();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка при чтении файла: {ex.Message}");
            return;
        }

        // Сортировка с учетом отношения порядка
        var sortedPoints = points.OrderBy(p => p.X).ThenBy(p => p.Y).ToList();

        // Запись отсортированных данных обратно в файл
        try
        {
            File.WriteAllLines(fileName, sortedPoints.Select(p => p.ToString()));
            Console.WriteLine("Данные успешно отсортированы и записаны обратно в файл.");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка при записи файла: {ex.Message}");
        }
    }
}