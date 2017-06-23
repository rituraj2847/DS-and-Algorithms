
package javaapplication2;
import java.util.Scanner;
public class BST {
    private Node root;
    class Node{
    int value;
    Node left,right;
    }
    public Node GetNewNode(int item){
    Node n=new Node();
    n.value=item;
    n.left=null;
    n.right=null;
    return n;
    }
    public void Insert(int data){
        root=Insert(data, root);
    }
    private Node Insert(int item, Node root){
        if(root==null){
        root=GetNewNode(item);
        }
        else if(item>root.value){
        root.right=Insert(item,root.right);
        }
        else root.left=Insert(item,root.left);
        return root;
    }
    public boolean Search(int item){
        return Search(item,root);
    }
    private boolean Search(int item, Node root){
    if (root==null) return false;
    else if(root.value==item) return true;
    else if(item>root.value) return Search(item,root.right);
    else return Search(item,root.left);
    }
    public int CountNodes(){
        return CountNodes(root);
    }
    private int CountNodes(Node root){
        if(root==null) return -1;
        else{
        int left_tree=CountNodes(root.left);
        int right_tree=CountNodes(root.right);
        return max(left_tree,right_tree)+1;
        }
        }
    private int max(int x, int y){
        return x>y?x:y;
    }
}
