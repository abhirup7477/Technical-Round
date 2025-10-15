// import java.util.*;

class Node<T>{
    T data;
    Node<T> next;
    Node(){
        this.data = null;
        this.next = null;
    }
    Node(T data){
        this.data = data;
        this.next = null;
    }
}

class LinkedList<T>{
    Node<T> head;

    LinkedList(){
        this.head = null;
    }

    @Override
    public String toString(){
        if(head == null){
            return "LinkedList is empty";
        }
        Node<T> ptr = head;
        StringBuilder sb = new StringBuilder();
        while(ptr.next != null){
            sb.append(ptr.data).append(" --> ");
            ptr = ptr.next;
        }
        sb.append(ptr.data);
        return sb.toString();
    }

    public void add(T data){
        Node<T> newNode  = new Node<>(data);
        if(head == null){
            head = newNode;
        }
        else{
            Node<T> ptr = head;
            while(ptr.next != null){
                ptr = ptr.next;
            }
            ptr.next = newNode;
        }
    }

    public void addFirst(T data){
        Node<T> newNode = new Node<>(data);
        newNode.next = head;
        head = newNode;
    }

    public T get(int index){
        if(index < 0){
            throw new IndexOutOfBoundsException(index + " is out of bounds");
        }
        else{
            Node<T> ptr = head;
            for(int i=0; i<=index; i++){
                if(ptr == null){
                    throw new IndexOutOfBoundsException(index + " is out of bounds");
                }
                else if(i == index){
                    return ptr.data;
                }
                else{
                    ptr = ptr.next;
                }
            }
        }
        return null;
    }

    public void set(int index, T data){
        if(index < 0){
            throw new IndexOutOfBoundsException(index + " is out of bounds");
        }
        else{
            Node<T> ptr = head;
            for(int i=0; i<=index; i++){
                if(ptr == null){
                    throw new IndexOutOfBoundsException(index + " is out of bounds");
                }
                else if(i == index){
                    ptr.data = data;
                }
                else{
                    ptr = ptr.next;
                }
            }
        }
    }

    public boolean isEmpty(){
        return (head == null);
    }

    public void remove(){
        if(isEmpty()){
            throw new IllegalStateException("Cannot remove from an empty list");
        }
        else if(head.next == null){
            head = null;
        }
        else{
            Node<T> ptr = head;
            Node<T> prev = null;
            while(ptr.next != null){
                prev = ptr;
                ptr = ptr.next;
            }
            prev.next = null;
        }
    }

    public void removeFirst(){
        if(isEmpty()){
            throw new IllegalStateException("Cannot remove from an empty list");
        }
        else{
            head = head.next;
        }
    }

    public void reverse(){
        Node<T> prev = null;
        Node<T> curr = head;
        Node<T> next = null;
        while(curr != null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    public int size(){
        Node<T> ptr = head;
        int count = 0;
        while(ptr != null){
            count++;
            ptr = ptr.next;
        }
        return count;
    }
}

public class LinkedListExample {
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        // list.remove();

        list.addFirst(20);
        list.add(1);
        
        list.add(2);
        list.add(3);

        list.addFirst(10);

        System.out.println(list);
        // System.out.println(list.size());
        // System.out.println(list.get(2));
        // System.out.println(list.get(list.size() - 1));
        // System.out.println(list.get(list.size()));
        
        list.reverse();
        System.out.println(list);
    }
}
