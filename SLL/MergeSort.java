import java.util.*;
import java.lang.*;
import java.io.*;

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

class Driverclass
{
    
    public static void main (String[] args) 
    {
        Scanner sc= new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            Node head = new Node(sc.nextInt());
            Node tail = head;
            while(n-- > 1){
		        tail.next = new Node(sc.nextInt());
		        tail = tail.next;
		    }
		   
		      head = new LinkedList().mergeSort(head);
		     printList(head);
		    System.out.println();
        }
    }
    public static void printList(Node head)
    {
        if(head == null)
           return;
           
        Node temp = head;
        while(temp != null)
        {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}


// } Driver Code Ends


//User function Template for Java
/*
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        this.data = key;
        next = null;
    }
} */

class LinkedList
{
    public static Node getmiddle(Node head){
        if(head == null){
            return head;
        }
        Node slow = head;
        Node fast = head;
        
        while(fast.next!= null && fast.next.next!= null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        return slow;
    }
    
    public static Node merging(Node left , Node right){
        Node result = null;
        
        if(left == null){
            return right;
        }
        if(right == null){
            return left;
        }
        
        if(left.data <= right.data){
            result = left;
            result.next = merging(left.next , right);
        }
        else{
            result = right;
            result.next = merging(left , right.next);
        }
        
        return result;
    }
    static Node mergeSort(Node head)
    {
        // add your code here
        if(head == null || head.next == null){
            return head;
        }
        
        Node middle = getmiddle(head);
        Node nextofmiddle = middle.next;
        
        middle.next = null;
        
        Node left = mergeSort(head);
        Node right = mergeSort(nextofmiddle);
        
        Node sortedlist = merging(left , right);
        
        return sortedlist;
    }
}


