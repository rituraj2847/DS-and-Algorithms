public class StackInLinkedLists {
    private Node head;
    StackInLinkedLists(int item){
    head=new Node();
    head.value=item;
    head.link=null;
    }
    class Node{
    private int value;
    private Node link;
    }
    public void Insert(int item){
    Node n=new Node();
    n.value=item;
    n.link=head;
    head=n;
    }
    public void Remove(){
    Node n=head;
    head=n.link;
    }
    public void Print(){
    Node z=head;
    while(z!=null){
    System.out.print(z.value);
    z=z.link;
    }
    System.out.println();
    }
    public static void main(String[] args){
    StackInLinkedLists list=new StackInLinkedLists(2);
    System.out.println("Before Pop Operation: ");
    list.Print();
    list.Insert(3); list.Print();
    list.Insert(6); list.Print();
    list.Insert(4); list.Print();
    list.Insert(1); list.Print();
    list.Remove();
    System.out.println("After Pop Operation: ");
    list.Print();
    }
}

