using System;

namespace Kaprekar
{
    class Program
    {
        public static int NumDigits(int n)
        {
            int count = 0;
            while (n != 0)
            {
                int r = n % 10;
                count++;
                n /= 10;
            }
            return count;
        }
        public static bool IsKaprekar(int n)
        {
            int digits = NumDigits(n);
            int sqr = (int)Math.Pow(n, 2);
            string sqrString = Convert.ToString(sqr);

            int.TryParse(sqrString.Substring(0, sqrString.Length - digits), out int l);
            int.TryParse(sqrString.Substring(sqrString.Length - digits), out int r);

            if (l + r == n) return true;
            return false;
            
        }
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("Input:");
                int lower = Convert.ToInt32(Console.ReadLine());
                int upper = Convert.ToInt32(Console.ReadLine());

                Console.WriteLine($"lower = {lower} and upper = {upper}");

                for (int i = lower; i <= upper; i++)
                {
                    if (IsKaprekar(i))
                    {
                        Console.Write(i + " ");
                    }
                }
                Console.WriteLine();
            }
            catch (System.Exception e)
            {
                Console.WriteLine("Error: " + e);
            }
        }
    }
}