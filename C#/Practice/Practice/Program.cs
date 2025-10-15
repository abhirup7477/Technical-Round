using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practice
{
    abstract class Shape
    {
        public double area;
        public Shape()
        {
            Console.WriteLine("Shape constructor called");
        }
        public abstract void computeArea();
        public abstract void displayArea();
    }
    class Rectangle : Shape
    {
        double height, width;
        public Rectangle(double h, double w)
        {
            Console.WriteLine("Rectangle constructor called");
            height = h;
            width = w;
        }

        public override void computeArea()
        {
            area = height * width;
        }

        public override void displayArea()
        {
            Console.WriteLine($"Area of Rectangle({height}, {width}): {area}");
        }

        public override string ToString()
        {
            return $"Rectangle({height}, {width}): {area}";
        }
    }

    class Triangle : Shape
    {
        double height, side;
        public Triangle(double h, double s)
        {
            Console.WriteLine("Triangle constructor called");
            height = h;
            side = s;
        }
        public override void computeArea()
        {
            area = 0.5 * height * side;
        }
        public override void displayArea()
        {
            Console.WriteLine($"Area of Triangle({height}, {side}): {area}");
        }
        public override string ToString()
        {
            return $"Triangle({height}, {side}): {area}";
        }
    }

    class RightAngledTriangle : Triangle
    {
        double angle;

        public double Angle
        {
            get { return angle; }
        }
        public RightAngledTriangle(double h, double s) : base(h, s)
        {
            Console.WriteLine("RightAngledTriangle constructor called");
            angle = 90;
        }
        public override string ToString()
        {
            return $"RightAngledTriangle => {base.ToString()}, angle: {angle}";
        }
    }

    internal class Program
    {
        public static void test(ref int num)
        {
            num = 2 * num;
        }

        public static void calculate(int a, int b, out int sum, out int product)
        {
            sum = a + b;
            product = a * b;
        }

        public static void sum(out int sum, params int[] nums)
        {
            sum = 0;
            foreach(int n in nums)
            {
                sum += n;
            }
        }

        interface IShape
        {
            double Area { get; set; }
        }

        class Test
        {
            public static int n = 20;
        }

        class Parent
        {
            public static int n = 10;
            public int num = 20;

            public void display()
            {
                Console.WriteLine($"n = {n}, num = {num}");
            }

            public static void show()
            {
                Console.WriteLine($"n = {n}");
                //Console.WriteLine($"num = {num}"); // Error: An object reference is required for the non-static field, method, or property 'Parent.num'
            }
        }

        class Child : Parent
        {
            //public void display()
            //{
            //    Console.WriteLine($"n = {n}, num = {num}");
            //    Console.WriteLine($"Parent n = {Parent.n}, Parent num = {base.num}");
            //}
            //public static void show()
            //{
            //    Console.WriteLine($"n = {n}");
            //    Console.WriteLine($"Parent n = {Parent.n}");
            //    //Console.WriteLine($"num = {num}"); // Error: An object reference is required for the non-static field, method, or property 'child.num'
            //    //Console.WriteLine($"Parent num = {base.num}"); // Error: A static member cannot reference an instance member in C#
            //}
        }

        int n = 10;
        static int n_static = 20;

        static void Main(string[] args)
        {
            //Console.Write("Input: ");
            //int input = int.Parse(Console.ReadLine());
            //Console.WriteLine($"Output: {input * 2}");

            //Console.Write("Input: ");
            //int input1 = Convert.ToInt32(Console.ReadLine());
            //Console.WriteLine($"Output: {input1 * 2}");

            //int input2;
            //Console.Write("Input: ");
            //if (int.TryParse(Console.ReadLine(), out input2) )
            //{
            //    Console.WriteLine($"Output: {input2 * 2}");
            //}
            //Console.WriteLine($"input2 = {input2}");

            //double price = 113.56975473;
            //double price1 = 113.56475473;
            //Console.WriteLine($"Price: {price:F2}");
            //Console.WriteLine($"Price: {price1:F2}");
            //Console.WriteLine("2 * {0} = {1}", price, 2 * price);



            ////Disctionary
            //string name = "abhirupbag";
            //Dictionary<char, int> freq = new Dictionary<char, int>();
            //foreach (char c in name)
            //{
            //    if (freq.ContainsKey(c))
            //    {
            //        freq[c]++;
            //    }
            //    else
            //    {
            //        freq[c] = 1;
            //    }
            //}

            //foreach(var pair in freq)
            //{
            //    Console.WriteLine($"{pair.Key}: {pair.Value}");
            //}



            //Rectangle r = new Rectangle(3.5, 5.4);
            //r.computeArea();
            //r.displayArea();
            //Console.WriteLine(r);

            //Triangle t1 = new Triangle(3.5, 5.4);
            //t1.computeArea();
            //t1.displayArea();
            //Console.WriteLine(t1);

            //RightAngledTriangle rt = new RightAngledTriangle(3.5, 5.4);
            //rt.computeArea();
            //rt.displayArea();
            //Console.WriteLine(rt);
            //Console.WriteLine($"Angle : {rt.Angle}");


            ////**************    ref, out, params     *************
            //int num = 10;
            //Console.WriteLine($"Before call by ref : {num}");
            //test(ref num);
            //Console.WriteLine($"After call by ref : {num}");

            //int s, p;
            //calculate(2, 3, out s, out p);
            //Console.WriteLine($"Sum = {s} and Product = {p}");

            //sum(out int total, 1, 2, 3, 4, 5);
            //Console.WriteLine($"Total = {total}");



            //Console.WriteLine("Non-Static variable n = " + n);  // Error: An object reference is required for the non-static field, method, or property 'Program.n'
            //Console.WriteLine("Non-Static variable n = " + this.n);  //Error: A static member cannot reference an instance member in C#
            //Console.WriteLine("Non-Static variable n = " + new Program().n); // Correct way to access non-static member from static context

            //Console.WriteLine("Static variable n = " + n_static);

            //Test test = new Test();
            //Console.WriteLine("Static variable n from Test class = " + Test.n);
            ////Console.WriteLine("Static variable n from Test class = " + test.n); // Error
            ///


            Console.WriteLine("Parent class static member access: " + Parent.n);
            Parent.show();
            Console.WriteLine("Child class static member access: " + Child.n);
            Child.show();
        }
    }
}
