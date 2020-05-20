import java.util.*;
import java.util.*;
import java.io.*;

class Node
{
    int data;
    Node next, prev;
    Node(int key)
    {
        data = key;
        next = prev = null;
    }
}

class QuickSort
{
    public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int t = sc.nextInt();
	    
	    while(t-- > 0)
	    {
	        int n = sc.nextInt();
	        int a1 = sc.nextInt();
	        Node head = new Node(a1);
	        Node temp = head;
	        
	        for (int i = 1;i < n;i++)
	        {
	            int a = sc.nextInt();
	            Node n1 = new Node(a);
	            n1.prev = temp;
	            temp.next = n1;
	            temp = n1;
	        }
	        
	        head = new LinkedList().sortDoubly(head);
	        printList(head);
	    }
	}
	public static void printList(Node node)
	{
	    Node temp = node;
	    while(node != null)
	    {
	        System.out.print(node.data + " ");
	        temp = node;
	        node = node.next;
	    }
	    System.out.println();
	    while(temp != null)
	    {
	        System.out.print(temp.data + " ");
	        temp = temp.prev;
	    }
	    System.out.println();
	}
}

class LinkedList
{
    
    static Node partition(Node start){
        Node slow = start;
        Node fast = start;
        
        while (fast.next != null && fast.next.next != null) { 
            fast = fast.next.next; 
            slow = slow.next; 
        } 
        Node temp = slow.next; 
        slow.next = null; 
        return temp; 
        
    }
    
    static Node merge(Node start , Node end){
        if(start == null){
            return end;
        }
        if(end == null){
            return start;
        }
        
        if (start.data < end.data) { 
            start.next = merge(start.next, end); 
            start.next.prev = start; 
            start.prev = null; 
            return start; 
        } else { 
            end.next = merge(start, end.next); 
            end.next.prev = end; 
            end.prev = null; 
            return end; 
        } 
    }
    
    static Node mergeSort(Node node) { 
        if (node == null || node.next == null) { 
            return node; 
        } 
        Node second = partition(node); 
  
        // Recur for left and right halves 
        node = mergeSort(node); 
        second = mergeSort(second); 
  
        // Merge the two sorted halves 
        return merge(node, second); 
    } 
    
    static Node sortDoubly(Node head)
    {
       Node p = null;
       p =mergeSort(head);
       return p;
    } 

}