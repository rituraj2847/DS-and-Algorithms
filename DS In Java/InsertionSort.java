
package javaapplication2;

import java.util.Scanner;

public class InsertionSort {
    private int items[];
    private int capacity;
    InsertionSort(int capacity){
    items=new int[capacity];
    }
    public void assign(){
          System.out.println("Enter any 6 items to be sorted");
        Scanner s=new Scanner(System.in);
    for(int i=0;i<items.length;i++){
        items[i]=s.nextInt();
    }
    }
    public void InsertionSort(){
        for(int i=0;i<items.length;i++){
        int pos=i;
        while(pos>0 && items[pos]<items[pos-1]){
            int temp=items[pos];
            items[pos]=items[pos-1];
            items[pos-1]=temp;
            pos--;
        }
        }
    }
    public void Print(){
    for(int i=0;i<items.length;i++){
    System.out.print(items[i]+" ");
    }
    }
public static void main(String[] args){
   InsertionSort t=new InsertionSort(6);
   t.assign();
   t.InsertionSort();
   t.Print();
    }
    
}
