using System;
using System.Text;

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
                Array.Reverse(arr);
                for (int i = 0; i < arr.Length; i++)
                {
                    char[] temp = arr[i].ToCharArray();
                    Array.Reverse(temp);
                    arr[i] = string.Join("", temp);
                }
                str = string.Join(" ", arr);
                Console.WriteLine(str);
            }
        }
    }
}