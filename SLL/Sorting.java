import java.util.*;

public class Sorting {

    Node head = null;

	static class Node{
		int data;
		Node next;

		Node(int d){
			data=d;
			next=null;
		}
	}

		void push(int d) 
    { 
        Node new_node = new Node(d); 
        /* link the old list off the new node */
        new_node.next = head; 
        /* move the head to point to the new node */
        head = new_node; 
    } 

	public static Node getmiddle(Node head)
	{
		if(head == null)
		{
			return head;
		}
		Node slow = head;
		Node fast = head;

		while(fast.next !=null && fast.next.next!=null)
		{
			slow = slow.next;
			fast = fast.next.next;
		}
		return slow;
	}

	void printList(Node headref)
	{ 
     while (headref != null) { 
            System.out.print(headref.data + " "); 
            headref = headref.next; 
     } 
  }

	Node Mergesort(Node h)
	{
		// Best Case 
		if(h== null || h.next == null)
		{
			return h;
		}

		//getting middle 
		Node middle = getmiddle(h);

		Node nextofmiddle = middle.next;

		middle.next = null;


		Node left = Mergesort(h);
		Node right= Mergesort(nextofmiddle);
		
		// combining the merges
		Node sorted = MergeCombine(left , right);
		return sorted;

	} 

	Node MergeCombine(Node a , Node b)
	{
		Node result =null;

		// Best Case 
		if(a == null)
		{
			return b;
		}
		if(b == null)
		{
			return a;
        }
        
        // pick either a or b 

		if(a.data <= b.data)
		{
			result = a;
			result.next = MergeCombine(a.next, b);
		}
		else
		{
			result = b;
			result.next = MergeCombine(a , b.next);
		}

		return result;	
	}

	public static void main(String args[])
	{
		Sorting list = new Sorting();
		list.push(3);
		list.push(1);
		list.push(90);
		list.push(2);

		list.head = list.Mergesort(list.head);
		list.printList(list.head);
	}
}