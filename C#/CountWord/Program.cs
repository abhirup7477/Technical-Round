using System;

namespace CountWord
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter the string : ");
            string str = new(Console.ReadLine());
            if (string.IsNullOrEmpty(str))
                Console.WriteLine("The input string is null or empty.");
            else
            {
                string[] arr = str.Split();
                Console.WriteLine($"Word count = {arr.Length}");
            }
        }
    }
}