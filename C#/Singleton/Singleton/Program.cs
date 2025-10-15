using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    class Singleton
    {
        private static Singleton obj = null;
        private Singleton() { }

        public static Singleton getInstance()
        {
            if(obj == null)
            {
                return new Singleton();
            }
            return obj;
        }
    }

    class Singleton_ThreadSafety
    {
        private static Singleton_ThreadSafety obj = null;
        private static readonly object lockObj = new object();

        private Singleton_ThreadSafety() { }

        public static Singleton_ThreadSafety getInstance()
        {
            lock (lockObj)
            {
                if(obj == null)
                {
                    return new Singleton_ThreadSafety();
                }
                return obj;
            }
        }
    }

    class Singleton_Eager
    {
        private static Singleton_Eager obj = new Singleton_Eager();
        private Singleton_Eager() { }

        public static Singleton_Eager getInstance()
        {
            return obj;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Singleton s1  = Singleton.getInstance();
            Singleton s2  = Singleton.getInstance();
            Console.WriteLine(s1.Equals(s2));
        }
    }
}
