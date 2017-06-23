
package javaapplication2;


import java.util.Scanner;

class BinarySearchTree{
    public static void main(String[] args){
        BST bst=new BST();
        char c;
        do{
        System.out.println("1. Insert");
        System.out.println("2. Search");
        System.out.println("3. CountNodes");
        //System.out.println("4. Delete");
        Scanner scan=new Scanner(System.in);
        
        int ch=scan.nextInt();
        switch(ch){
            case 1: 
                System.out.println("Enter element to be inserted:");
                        bst.Insert(scan.nextInt());
                        break;
            case 2:
                System.out.println("Enter element to be searched:");
                        System.out.println("Search Result: "+ bst.Search(scan.nextInt()));
                        break;
            case 3:
                bst.CountNodes();
                        break;
            /*case 4: 
                System.out.println("Enter element to be deleted:");
                        bst.Delete(scan.nextInt());
                        break;*/
            default: break;
    }
    System.out.println("Want to perform more('Y' or 'N')");
            c=scan.next().charAt(0);
        } while(c=='Y' || c=='y');
    }}
