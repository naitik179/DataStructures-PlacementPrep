import java.util.*;
class Node {
    int data;
    Node next;
    Node(int d) {
        data = d;
        next = null;
    }
} 

class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while (t-- > 0) {
            int n = sc.nextInt();
            
            int a = sc.nextInt();
            Node head = new Node(a);
            Node tail = head;
            
            for (int i=0; i<n-1; i++)
            {
                a = sc.nextInt();
                tail.next = new Node(a);
                tail = tail.next;
            }
            
            int k = sc.nextInt();
            
            Rotate g = new Rotate();
            head = g.rotate(head,k);
            printList(head);
        }
    }
    
    public static void printList(Node n) {
        while (n != null) {
            System.out.print(n.data + " ");
            n = n.next;
        }
        System.out.println();
    }
}

class Rotate{
    // This function should rotate list counter-
    // clockwise by k and return head node
    
    public Node rotate(Node head, int k) {
        // add code here
        
        if(head == null){
            return null;
        }
        else{
            int count = 0;
            Node ptr = head;
            Node acthead = head;
            Node prev = null;
            while(count < k && ptr!=null){
                prev = ptr;
                ptr = ptr.next;
                count++;
            }
            if(ptr == null){
                return head;
            }
            
            prev.next = null;
            head = ptr;
            
            Node ptr1 = ptr;
            while(ptr1.next!=null){
                ptr1 = ptr1.next;
            }
            
            ptr1.next = acthead;
            return head;
        }
    }
}
