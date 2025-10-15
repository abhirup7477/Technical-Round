using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CanConstructString
{
    internal class Program
    {
        public static bool CanConstruct(string ransomNote, string magazine)
        {
            Dictionary<char, int> Count = new Dictionary<char, int>();
            foreach (char ch in magazine)
            {
                if (Count.ContainsKey(ch))
                {
                    Count[ch]++;
                }
                else
                {
                    Count[ch] = 1;
                }
            }
            foreach (var ch in ransomNote)
            {
                if (!Count.ContainsKey(ch) || Count[ch] == 0)
                {
                    return false;
                }
                else
                {
                    Count[ch]--;
                    if (Count[ch] < 0)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        static void Main(string[] args)
        {
            Console.Write("Enter RnsomeNote: ");
            string RansomeNote = Console.ReadLine();
            Console.Write("Wnter Magazine: ");
            string Magazine = Console.ReadLine();
            Console.WriteLine(CanConstruct(RansomeNote, Magazine));
        }
    }
}
