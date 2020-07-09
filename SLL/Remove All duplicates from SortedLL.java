class LinkedList 
{ 
	Node head=null; /* head of linked list */
	class Node 
	{ 
		int val; /* value in the node */
		Node next; 
		Node(int v) 
		{ 
			/* default value of the next 
			pointer field */
			val = v; 
			next = null; 
		} 
	} 
	public void insert(int data) 
	{ 
		Node new_node = new Node(data); 
		new_node.next = head; 
		head = new_node; 
	} 

	/* Function to remove all occurrences 
	of duplicate elements */
	public void removeAllDuplicates() 
	{ 
	/* create a dummy node that acts like a fake 
		head of list pointing to the original head*/
		Node dummy = new Node(0); 

		/* dummy node points to the original head*/
		dummy.next = head; 
		Node prev = dummy; 
		current = head; 

		while (current != null) 
		{ 
			/* Until the current and previous values 
			are same, keep updating current */
			while (current.next != null && 
				prev.next.val == current.next.val) 
				current = current.next; 

			/* if current has unique value i.e current 
				is not updated, Move the prev pointer 
				to next node*/
			if (prev.next == current) 
				prev = prev.next; 

			/* when current is updated to the last 
			duplicate value of that segment, make 
			prev the next of current*/
			else
				prev.next = current.next; 

			current = current.next; 
		} 

		/* update original head to the next of dummy 
		node */
		head = dummy.next; 
	} 
	public void printList() 
	{ 
		Node trav=head; 
		if (head==null) 
			System.out.print(" List is empty" ); 
		while (trav != null) 
		{ 
			System.out.print(trav.val + " "); 
			trav = trav.next; 
		} 
	} 

	public static void main(String[] args) 
	{ 
		LinkedList ll = new LinkedList(); 
		ll.insert(53); 
		ll.insert(53); 
		ll.insert(49); 
		ll.insert(49); 
		ll.insert(35); 
		ll.insert(28); 
		ll.insert(28); 
		ll.insert(23); 
		System.out.println("Before removal of duplicates"); 
		ll.printList(); 

		ll.removeAllDuplicates(); 

		System.out.println("\nAfter removal of duplicates"); 
		ll.printList(); 
	} 
} 
