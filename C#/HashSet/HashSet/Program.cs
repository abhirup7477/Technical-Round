using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashSet
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a string: ");
            string str = Console.ReadLine();
            HashSet<char> chars = new HashSet<char>();


            //char firstRepeatingCharacter = '\0';
            //foreach (char ch in str)
            //{
            //    if (!chars.Contains(ch))
            //    {
            //        chars.Add(ch);
            //    }
            //    else
            //    {
            //        firstRepeatingCharacter = ch;
            //        break;
            //    }
            //    Console.WriteLine(ch);
            //}
            //if (firstRepeatingCharacter != '\0')
            //    Console.WriteLine("First repeating character: " + firstRepeatingCharacter);
            //else
            //    Console.WriteLine("There is no repeating character.");

            //chars.Clear();
            //bool isNonRepeatingPresent = false;
            //foreach(char ch in str)
            //{
            //    if (!chars.Contains(ch))
            //    {
            //        chars.Add(ch);
            //    }
            //    else
            //    {
            //        chars.Remove(ch);
            //    }
            //}
            //Console.WriteLine(string.Join(", ", chars));
            //Console.WriteLine(chars.FirstOrDefault());
            ////Console.WriteLine(chars.ElementAt(0));
            //foreach (char ch in str)
            //{
            //    if (chars.Contains(ch))
            //    {
            //        Console.WriteLine($"First non-repeating character is {ch}");
            //        isNonRepeatingPresent = true;
            //        break;
            //    }
            //}
            //if (!isNonRepeatingPresent)
            //{
            //    Console.WriteLine("NO non-repeating character is present");
            //}

            //Console.WriteLine(chars.Count);


            //chars.Add('a');
            //Console.WriteLine(string.Join(", ", chars));
            //chars.Add('a');
            //Console.WriteLine(string.Join(", ", chars));


            foreach (char ch in str)
            {
                chars.Add(ch);
            }
            Console.WriteLine(string.Join(", ", chars));
        }
    }
}
