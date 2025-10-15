import java.util.*;

class A{
    int a;
    A(){
        System.out.println("Creating object- A");
    }
    A(int a){
        this.a = a;
        System.out.println("Creating A : value - " + a);
    }
}

class B extends A{
    int b;
    B(){
        System.out.println("Creating object- B");
    }
    B(int b){
        // super(b); // calls the parameterised constructor of A
        this.b = b;
        System.out.println("Creating B : value - " + b);
    }
}

class C extends B{
    int c = 30;
    C(){
        System.out.println("Creating object- C");
    }
}

public class Test {
    public static void main(String[] args) {
        // int n = 10;
        // for(int i=1; i <= n; i++){
        //     System.out.print(i + " ");
        //     if(i == 5){
        //         n = 6;
        //    }
        // }
        // System.out.println();



        // ArrayList<Integer> list = new ArrayList<>();
        // int arr[] = {1, 8, 4, 1, 4, 1, 2, 2, 8, 1};
        // for(int i : arr)
        //     list.add(i);
        // // list[0] = 10; // //This line will cause an error because ArrayList does not support direct indexing like arrays.
        // System.out.println(list);
        // System.out.println(list.get(1));
        // list.set(1, 10);
        // System.out.println(list);
        // List<String> lst = new ArrayList<>();
        // for(int i=0; i<list.size(); i++){
        //     lst.add(i, list.get(i).toString());
        // }
        // System.out.println(lst);
        // System.out.println(lst.get(0).getClass());



        // int arr[] = {1, 8, 4, 1, 4, 1, 2, 2, 8, 1};
        // Arrays.sort(arr);
        // System.out.println(Arrays.toString(arr));


        
        // Integer num1 = 23;
        // Integer num2 = 20;
        // System.out.println(num1.compareTo(num2));


        // A a = new A();
        // B b = new B();

        // C c = new C();
        // System.out.println(c.a);
        // System.out.println(c.b);
        // System.out.println(c.c);

        // B b = new C();
        // System.out.println(b.a);
        // System.out.println(b.b);
        // System.out.println(b.c); b is of type, B, so it can not access attributes or methods of C, (subclass).


        // B b = new B(20);
    }
}