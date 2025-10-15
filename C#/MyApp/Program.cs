// See https://aka.ms/new-console-template for more information
using System;
using System.Numerics;

namespace MyApp
{
    // class A
    // {
    //     int a;
    //     public A()
    //     {
    //         Console.WriteLine($"Creating A");
    //     }
    //     public A(int a)
    //     {
    //         this.a = a;
    //         Console.WriteLine($"Creating A with value {this.a}");
    //     }
    // }

    // class B : A
    // {
    //     int b;
    //     public B(int b)
    //     {
    //         this.b = b;
    //         Console.WriteLine($"Creating A with value {this.b}");
    //     }
    // }
    class Program
    {
        static void Main(string[] args)
        {
            // string name = "Abhirup" + " Bag";
            // Console.WriteLine(name.Length);
            // Console.WriteLine(name.ToUpper());
            // Console.WriteLine(name.GetType());
            // Console.WriteLine(name.Contains("Bag"));
            // Console.WriteLine(name.IndexOf("Bag"));
            // Console.WriteLine(name[4]);
            // Console.WriteLine(name.Substring(3, 7));

            //datatypes int, float, double, decimal, string, bool etc.
            //Console.ReadLine() takes input in string format

            // int n = Console.Write("Input : "); //con not be implicitly converted from string to int
            // Console.Write("Enter a number: ");
            // int n = Convert.ToInt32(Console.ReadLine());
            // Console.WriteLine("n = " + n);

            // BigInteger num = new BigInteger(n);
            // Console.WriteLine("Bit length: " + num.GetBitLength() + "\nByte count: " + num.GetByteCount());


            // A a = new A(10);
            // B b = new B(20);


            // try
            // {
            //     int num = Convert.ToInt32(Console.ReadLine());
            // }
            // catch (Exception e)
            // {
            //     // Console.WriteLine(e);
            //     Console.WriteLine(e.Message);
            //     // Console.WriteLine(e.Data);
            //     // Console.WriteLine(e.GetBaseException());
            // }


            // int n = Console.Read();
            // Console.WriteLine(n);
            // char ch = Convert.ToChar(Console.Read());
            // // char ch = (char) Console.Read();
            // Console.WriteLine(ch);

            // string str = "";
            // while ((ch = (char)Console.Read()) != ' ')
            // {
            //     str += ch;
            // }
            // Console.WriteLine(str);


            //TryPass
            // bool success = false;
            // while (!success)
            // {
            //     if (int.TryParse(Console.ReadLine(), out int num))
            //     {
            //         success = true;
            //         Console.WriteLine(num);
            //     }
            //     else
            //     {
            //         Console.WriteLine("Wrong format!");
            //     }
            // }


            // char[] chars = { 'a', 'b', 'h', 'i' };
            // string name = new string(chars);
            // string str = new string("abhi");
            // if (str == name)
            // {
            //     Console.WriteLine("Same");
            // }
            // else
            // {
            //     Console.WriteLine("Not same");
            // }
            // object obj = new string(chars);
            // if (obj == name) //warning
            // {
            //     Console.WriteLine("Same");
            // }
            // else
            // {
            //     Console.WriteLine("Not same"); // not same
            // }
            // if (obj.Equals(name))
            // {
            //     Console.WriteLine("Same");
            // }
            // else
            // {
            //     Console.WriteLine("Not same");
            // }


            string str = "Abhirup is now staring to get furstated and worried at the same time as he wasn't selected for any inverview so far.";
            for (int i = 0; i < str.Length; i++)
            {
                Console.Write(str[i]);
                Thread.Sleep(50);    //Thread
            }
        }
    }
}
