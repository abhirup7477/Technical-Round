import java.util.*;

interface Test1{
    int n = 10;
    default void display(){
        System.out.println("This is test1 interface: default method");
    }
    void testing();
    static void staticMethod(){
        System.out.println("This is static method");
    }
}

interface Test2{
    int n = 20;
    default void display(){
        System.out.println("This is test2 interface: default method");
    }
    void testing();
    static void staticMethod(){
        System.out.println("This is static method");
    }
}

class Tester1 implements Test1{
    Tester1(){
        System.out.println("Creating Tester1 object");
    }
    @Override
    public void testing(){
        System.out.println("Tester1 is testing");
    };
}

class Tester2 implements Test1, Test2{ // same default mrthod in both interface so overide it
    Tester2(){
        System.out.println("Creating Tester1 object");
    }
    @Override
    public void testing(){
        System.out.println("Tester1 is testing");
    };

    @Override
    public void display(){
        System.out.println("Default method with same signature has to be overriden");
    }
}

public class PracticeInterface {
    public static void main(String[] args){
        Tester1 t1 = new Tester1();
        System.out.println(t1.n);// works but should be accessed in a static way
        System.out.println(Test1.n);// accessing in a static way
        t1.testing();
        t1.display();
        // t1.staticMethod(); // // Error
        Test1.staticMethod();
    }
}
