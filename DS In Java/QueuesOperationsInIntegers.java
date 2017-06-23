
import java.util.*;
import java.lang.*;

public class QueuesOperationsInIntegers {
    private int[] items;        
    private int n=-1;
    private int front=-1;
    private int rear=-1;
    QueuesOperationsInIntegers(int capacity){
    items=new int[capacity];
    }
    public void Enqueue(int e){
    if(front==-1 && rear==-1){
    items[++front]=e;
    rear++;
    }
    else if(IsFull()){
    return;
    }
    else {
    items[++rear]=e;
    }
    }
    public void Dequeue(){
    if(IsEmpty()){
    return;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else {
        front=(front+1)%items.length;
    }
    }
    public void Print(){
        try{
    for(int i=0;i<(rear+(items.length)-front)%items.length +1;i++){
        int index=(front+i)%items.length;
		System.out.println(items[index]);
    }}
    catch(Exception e){
            System.out.println("Error");
            }
        }
    public boolean IsEmpty(){
    return front==-1;
    }
    public boolean IsFull(){
    return front==(rear+1)%items.length;
    }
    public static void main(String[] args){
        QueuesOperationsInIntegers queue=new QueuesOperationsInIntegers(5);
        Scanner s=new Scanner(System.in);
    System.out.println("Enter 4 items :");
    int i=0;
    while(i<4){
    queue.Enqueue(s.nextInt());
    i++;
    }
    System.out.println("Before Dequeue :");
    queue.Print();
    queue.Dequeue();
    System.out.println("After Dequeue :");
    queue.Print();
    }
    
}

