using System;
using System.Runtime.InteropServices.Marshalling;
using System.Globalization;
using System.Text;

namespace String
{
    class Program
    {
        static void Main(string[] args)
        {
            string name = "Abhirup Vag";
            string roll = "13000122082";

            Console.WriteLine($"Length of name = {name.Length}\nLength of roll = {roll.Length}");

            // name = name.Replace("V", "B");
            Console.WriteLine("name = " + name);

            Console.WriteLine(name.Substring(0, 7));
            Console.WriteLine(name[^3..]);
            Console.WriteLine(roll[..^0]);
            Console.WriteLine(roll[..^1]);
            Console.WriteLine(roll.IndexOf('2'));
            Console.WriteLine(roll.IndexOf("22"));
            Console.WriteLine(roll.LastIndexOf('2'));

            Console.WriteLine("\n\nModification");
            name = name.Replace('V', 'B');
            Console.WriteLine(name);
            string temp = "   1 2 3 4 , , , 5 6 789    @   ";
            temp = temp.Trim();
            Console.WriteLine(temp + $" => Length = {temp.Length}");
            // temp = temp.Trim('@');
            // or,
            temp = temp.Remove(temp.Length - 1);
            Console.WriteLine(temp + $" => Length = {temp.Length}");
            temp = temp.Trim();
            Console.WriteLine(temp + $" => Length = {temp.Length}");

            temp = temp.Replace(", ", "");
            // temp = temp.Replace(" ", "");
            Console.WriteLine(temp);
            string[] arr = temp.Split();
            Console.WriteLine(arr);
            foreach (string str in arr)
            {
                Console.Write(string.Format("\"{0}\" ", str));
            }
            Console.WriteLine();
            string str1 = string.Join(" ", arr);
            Console.WriteLine(str1);

            Console.WriteLine(roll = roll.PadLeft(roll.Length + 5, '@'));
            Console.WriteLine(roll);


            Console.WriteLine("\n\nCase conversion:\n");
            Console.WriteLine(name.ToUpper());
            Console.WriteLine(name.ToLower());
            string s = "My name is Abhirup Bag. I am pursuing BTECH form TMSL.";

            // TextInfo textInfo = CultureInfo.CurrentCulture.TextInfo;
            // s = textInfo.ToTitleCase(s);
            // or,
            // s = CultureInfo.CurrentCulture.TextInfo.ToTitleCase(s);
            // or,
            arr = s.Split(" ");
            int i;
            for (i = 0; i < arr.Length; i++)
            {
                char[] tempArr = arr[i].ToCharArray();
                tempArr[0] = char.ToUpper(tempArr[0]);
                arr[i] = string.Join("", tempArr);
            }
            s = string.Join(" ", arr);
            Console.WriteLine(s);


            // String is imutable in Python, Java, C# etc,
            // String: Synchronisation, Thread safety, for constant/Read-only value
            // StringBuilder: No Synchronisation, No Thread safety, for frequesntly changing value in single threaded program.

            // StringBuilder
            StringBuilder sb = new StringBuilder();//Empty 
            StringBuilder sb1 = new StringBuilder("Hello");
            StringBuilder sb2 = new StringBuilder(50); //capacity 50 
            StringBuilder sb3 = new StringBuilder("Hi", 5); //string + capacity 

            sb1.Append(" World!");
            Console.WriteLine(sb1);
            sb3.Append(" Abhirup!");
            Console.WriteLine(sb3);

            // s = "My name is Abhirup Bag. I am pursuing BTECH form TMSL.";
            arr = s.Split('.');
            for (i = 0; i < arr.Length - 1; i++)
            {
                sb.Append(arr[i].Trim());
                sb.Append('.');
                sb.AppendLine();
            }
            sb.Append(arr[i].Trim());
            // sb.Append('.');
            Console.WriteLine(sb);
            Console.WriteLine(sb.ToString());
        }
    }
}
