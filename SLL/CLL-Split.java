class CLL-Split { 

	static Node head, head1, head2; 

	static class Node { 

		int data; 
		Node next, prev; 

		Node(int d) { 
			data = d; 
			next = prev = null; 
		} 
	} 

	/* Function to split a list (starting with head) into two lists. 
	head1_ref and head2_ref are references to head nodes of 
	the two resultant linked lists */

	void splitList() { 
		Node slow_ptr = head; 
		Node fast_ptr = head; 

		if (head == null) { 
			return; 
		} 

		/* If there are odd nodes in the circular list then 
		fast_ptr->next becomes head and for even nodes 
		fast_ptr->next->next becomes head */
		while (fast_ptr.next != head 
				&& fast_ptr.next.next != head) { 
			fast_ptr = fast_ptr.next.next; 
			slow_ptr = slow_ptr.next; 
		} 

		/* If there are even elements in list then move fast_ptr */
		if (fast_ptr.next.next == head) { 
			fast_ptr = fast_ptr.next; 
		} 

		/* Set the head pointer of first half */
		head1 = head; 

		/* Set the head pointer of second half */
		// to check if there is only one node then no head2 will be assigned 
		if (head.next != head) { 
			head2 = slow_ptr.next; 
		} 

		/* Make second half circular */
		fast_ptr.next = slow_ptr.next; 

		/* Make first half circular */
		slow_ptr.next = head; 
	} 

	
	void printList(Node node) { 
		Node temp = node; 
		if (node != null) { 
			do { 
				System.out.print(temp.data + " "); 
				temp = temp.next; 
			} while (temp != node); 
		} 
	} 

	public static void main(String[] args) { 
		CLL-Split list = new CLL-Split(); 

		
		list.head = new Node(12); 
		list.head.next = new Node(56); 
		list.head.next.next = new Node(2); 
		list.head.next.next.next = new Node(11); 
		list.head.next.next.next.next = list.head; 

		System.out.println("Original Circular Linked list "); 
		list.printList(head); 

		list.splitList(); 
		System.out.println(""); 
		System.out.println("First Circular List "); 
		list.printList(head1); 
		System.out.println(""); 
		System.out.println("Second Circular List "); 
		list.printList(head2); 
		
	} 
} 
 
