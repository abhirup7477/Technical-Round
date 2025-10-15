using System;
using System.Threading.Tasks.Dataflow;
using System.Globalization;
using System.Collections;
using System.Security.Cryptography.X509Certificates;
using System.Runtime.InteropServices;

namespace Test
{
    class Student
    {
        private string name;
        private long roll;
        public Student(string name, long roll)
        {
            this.name = name;
            this.roll = roll;
        }
        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        //Auto implemented property
        public long Roll
        {
            get { return roll; }
            set { roll = value; }
        }

        public override string ToString()
        {
            return $"Name: {name} & Roll: {roll}";
        }
    }
    class StudentSorter : IComparer<Student>
    {
        public int Compare(Student? s1, Student? s2)
        {
            if (s1 is null && s2 is null) return 0;
            if (s1 is null) return -1;
            if (s2 is null) return 1;

            int nameCompare = s1.Name.CompareTo(s2.Name);
            if (nameCompare != 0)
            {
                return nameCompare;
            }
            return s1.Roll.CompareTo(s2.Roll);
        }
    }

    class Employee
    {
        string firstName;
        string lastName;
        int salary;
        public Employee(string firstName, string lastName, int salary)
        {
            this.firstName = firstName;
            this.lastName = lastName;
            this.salary = salary;
        }
        public string FullName
        {
            get { return $"{firstName} {lastName}"; }
        }
        public int Salary
        {
            get { return salary; }
            set { salary = value; }
        }
        public override string ToString()
        {
            return $"{FullName}: {Salary}";
        }
    }

    class EmployeeComparer : IComparer<Employee>
    {
        public int Compare(Employee? e1, Employee? e2)
        {
            if (e1 == null && e2 == null) return 0;
            if (e1 == null) return -1;
            if (e2 == null) return 1;

            int nameCompare = string.Compare(e1.FullName, e2.FullName, true);
            // or,
            int compare = string.Compare(e1.FullName, e2.FullName, StringComparison.OrdinalIgnoreCase);
            if (nameCompare != 0) return nameCompare;
            return e1.Salary.CompareTo(e2.Salary);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            // Console.WriteLine("Hello Abhirup!");
            // List<int> arr = new List<int>();
            // List<int> arr1 = new() { 1, 2, 3, 4 };
            // for (int i = 1; i <= 10; i++)
            // {
            //     arr.Add(i);
            // }
            // Console.WriteLine(arr);
            // Console.WriteLine(arr.Contains(2));
            // // arr.AddRange()
            // foreach (int item in arr)
            // {
            //     Console.Write(item + " ");
            // }
            // Console.WriteLine();

            // arr.Sort();
            // arr.Remove(3);
            // arr.RemoveAt(2);
            // arr.Reverse();
            // arr.Sort((a, b) => b.CompareTo(a));



            //List<>

            // Student s1 = new("Abhirup Bag", 13000122082);
            // Student s2 = new("Abhrajit Rath", 13000122078);
            // Console.WriteLine(s1);
            // List<Student> students = new() { s1, s2 };
            // students.Add(new("Abhirup Bag", 13000122083));
            // students.Add(new("Arnab Chatterjee", 13000122068));
            // students.Add(new("Arnab Chatterjee", 13000122065));
            // Console.WriteLine($"[{string.Join(", ", students)}]");
            // students.Sort(new StudentSorter());
            // Console.WriteLine($"[{string.Join(", ", students)}]");

            // Console.WriteLine(students[3].Name.Equals(students[4].Name));
            // Console.WriteLine(students[3].Roll.CompareTo(students[4].Roll));
            // Console.WriteLine(students[3].Roll);
            // Console.WriteLine(students[4].Roll);
            // Console.WriteLine(students[0]);
            // Console.WriteLine(students[1]);
            // Console.WriteLine(students[2]);
            // Console.WriteLine(students[3]);
            // Console.WriteLine(students[4]);



            //Dictionary<>

            Dictionary<int, Employee> employees = new(){
                {1, new Employee("Abhirup", "Bag", 40000)},
                {2, new ("Aninda", "Bag", 40000)},
                {3, new ("Abhrajit", "Rath", 45000)}
            };
            employees.Add(4, new("Arnab", "Chatterjee", 60000));
            Console.WriteLine(employees[1].FullName);
            Console.WriteLine(string.Join(", ", employees));
            Console.WriteLine(employees.ContainsKey(1));
            Console.WriteLine(employees.ContainsValue(new("Aninda", "Bag", 40000)));//false - since creating new object. Neef to override public bool Equals(Employee? obj) & public int HashCode()

            foreach (var item in employees)
            {
                Console.WriteLine($"{item.Key} => {item.Value}");
            }
            Console.WriteLine();
            for (int i = 0; i < employees.Count; i++)
            {
                KeyValuePair<int, Employee> pair = employees.ElementAt(i);
                Console.WriteLine($"{pair.Key} => {pair.Value}");
            }

            if (employees.TryGetValue(2, out Employee? e))
            {
                Console.WriteLine(employees[2]);
            }

            OrderedDictionary<string, string> dict = new OrderedDictionary<string, string>
            {
                {"Math", "abc"},
                {"Chemistry", "bsvd"},
                {"Bengali", "vkbkv"},
                {"Physics", "fkvd"}
            };
            Console.WriteLine($"[{string.Join(", ", dict)}]");
            if (dict.TryGetValue("Math", out string? teacher) && !string.IsNullOrEmpty(teacher))
            {
                Console.WriteLine($"Math: {teacher}");
            }
            // Console.WriteLine(dict[0]);//Error



            //HashSet

            HashSet<int> set = new() { 1, 2, 4, 1, 2, 9, 10, 4 };
            set.Add(3);
            Console.WriteLine("\n" + string.Join(", ", set));
            int[] arr = new int[set.Count];
            set.CopyTo(arr);
            Console.WriteLine(string.Join(", ", arr));



            //SortedSet<>

            SortedSet<Employee> employeeSet = new(new EmployeeComparer()) {
                new ("Abhrajit", "Rath", 45000),
                new Employee("Abhirup", "Bag", 40000),
                new Employee("Abhirup", "Bag", 50000),
                new ("Aninda", "Bag", 40000),
                new("Arnab", "Chatterjee", 60000),
                new ("Aninda", "Bag", 45000),
            };
            Console.WriteLine("\n" + $"[{string.Join(", ", employeeSet)}]");


            int[] arr1 = { 1, 2, 3, 4, 5 };
            int d = 2;
            d = d % arr1.Length;

            // //Left Rotate
            Console.WriteLine("\nLeft Rotate an array");
            Array.Reverse(arr1, 0, d);
            Console.WriteLine(string.Join(", ", arr1));
            Array.Reverse(arr1, d, arr1.Length - d);
            Console.WriteLine(string.Join(", ", arr1));
            Array.Reverse(arr1);
            Console.WriteLine(string.Join(", ", arr1));

            // //Right Rotate
            Console.WriteLine("\nRight Rotate an array");
            Array.Reverse(arr1, 0, arr1.Length - d);
            Console.WriteLine(string.Join(", ", arr1));
            Array.Reverse(arr1, arr1.Length - d, d);
            Console.WriteLine(string.Join(", ", arr1));
            Array.Reverse(arr1);
            Console.WriteLine(string.Join(", ", arr1));

            Console.WriteLine(arr1.Sum());
            Console.WriteLine(arr1.Average());
        }
    }
}