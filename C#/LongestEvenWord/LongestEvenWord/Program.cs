using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LongestEvenWord
{
    internal class Program
    {
        public static string FindLongestEvenWord(string input)
        {
            string[] words = input.Split(' ');
            int maxLen = 0;
            StringBuilder longestEvenWord = new StringBuilder("00");
            foreach(string word in words)
            {
                if (word.Length % 2 == 0 && word.Length > maxLen)
                {
                    longestEvenWord.Clear();
                    longestEvenWord.Append(word);
                    maxLen = word.Length;
                }
            }
            return longestEvenWord.ToString();
        }
        static void Main(string[] args)
        {
            //string input = "This is a test sentence with some even length words";
            string input = "Thids ics a tesdt width somde evden words";
            string longestEvenWord = FindLongestEvenWord(input);
            Console.WriteLine($"The longest even length word is: {longestEvenWord}");

            //Console.ReadLine();
        }
    }
}
