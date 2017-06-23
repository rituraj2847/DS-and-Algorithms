package javaapplication2;

import java.util.Scanner;

public class SelectionSort {
    private int items[];
    private int capacity;
    SelectionSort(int capacity){
    items=new int[capacity];
    }
     public void assign(){
           System.out.println("Enter any 6 items to be sorted");
        Scanner s=new Scanner(System.in);
    for(int i=0;i<items.length;i++){
        items[i]=s.nextInt();
    }
    }
    public void SelectionSort(){
        for(int i=0;i<items.length;i++){
        int minpos=i;
        for(int j=minpos;j<items.length;j++){
            if(items[minpos]>items[j]){
                minpos=j;
            }
        }
            int temp=items[minpos];
            items[minpos]=items[i];
            items[i]=temp;
        }
        }
    public void Print(){
    for(int i=0;i<items.length;i++){
    System.out.print(items[i]+" ");
    }
    }
    public static void main(String[] args){
   SelectionSort t=new SelectionSort(6);
   t.assign();
   t.SelectionSort();
   t.Print();
    }
}
