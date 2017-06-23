

public class QueuesInLinkedLists {
    private Node head;
    private Node front;
    private Node rear;
    class Node{
    private int value;
    private Node link;
    }
    QueuesInLinkedLists(int item){
        head=new Node();
        head.value=item;
        head.link=null;
        front=head;
        rear=head;
    }
    public void Enqueue(int item){
    Node n=new Node();
    n.value=item;
    n.link=null;
    rear.link=n;
    rear=n;
    }
    public void Print(){
    Node z=front;
    while(z!=null){
    System.out.print(z.value);
    z=z.link;
    }
    System.out.println();
    }
    public void Dequeue(){
    Node n=front;
    front=n.link;
    }
    public static void main(String[] args){
    QueuesInLinkedLists list=new QueuesInLinkedLists(3);
    System.out.println("Before Dequeue Operation");
    list.Print();
    list.Enqueue(4); list.Print();
    list.Enqueue(2); list.Print();
    list.Enqueue(1); list.Print();
    list.Enqueue(5); list.Print();
    list.Enqueue(7); list.Print();
    list.Dequeue();
    System.out.println("After Dequeue Operation :");
    list.Print();}
}

