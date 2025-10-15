using System;

namespace CountInString
{
    class Solution
    {
        static int CountLetter(string str)
        {
            int count = 0;
            // if (string.IsNullOrEmpty(str)) return 0;
            foreach (char ch in str)
            {
                if (char.IsLetter(ch))
                {
                    count++;
                }
            }
            return count;
        }
        static int CountDigit(string str)
        {
            int count = 0;
            foreach (char ch in str)
            {
                if (char.IsDigit(ch))
                {
                    count++;
                }
            }
            return count;
        }
        static void Main(string[] args)
        {
            Console.Write("Enter the string:  ");
            string str = new(Console.ReadLine());
            // string? str = Console.ReadLine();
            if (string.IsNullOrEmpty(str))
                Console.WriteLine("str is null or empty");
            else
                Console.WriteLine($"str = {str}");
            int digits = CountDigit(str);
            int letters = CountLetter(str);
            Console.WriteLine($"Count of digits = {digits}");
            Console.WriteLine($"Count of letters = {letters}");
        }
    }
}