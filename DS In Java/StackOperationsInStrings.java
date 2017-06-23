
import java.util.*;
import java.lang.*;

public class StackOperationsInStrings {
    private String[] items;     //Stack Of Strings
    private int n=-1;              //no of items
    StackOperationsInStrings (int capacity){
          items=new String[capacity];
    }
    public void Push(String e){
        items[++n]=e;
    }
    public String Pop(){
        return items[n--];
    }
    public boolean IsEmpty(){
        return n==-1;
    }
    public boolean IsFull(){
    return n==items.length;
    }

    
    public static void main(String[] args){
        int i=0;
    StackOperationsInStrings stack=new StackOperationsInStrings(5);
    System.out.println("Enter 3 strings to be pushed :");
    Scanner s=new Scanner(System.in);
     while(i<3){
    stack.Push(s.next());
    i++;
    }
    System.out.println("Pop yields :\n"+ stack.Pop());
            }
}


