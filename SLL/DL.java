class DL { 
	static Node head; 
	static class Node { 

		int data; 
		Node next; 

		Node(int d) 
		{ 
			data = d; 
			next = null; 
		} 
	} 

	int detectAndRemoveLoop(Node node) 
	{ 
		Node slow = node, fast = node; 
		while (slow != null && fast != null && fast.next != null) { 
			slow = slow.next; 
			fast = fast.next.next; 

			if (slow == fast) { 
				removeLoop(slow, node); 
				return 1; 
			} 
		} 
		return 0; 
	} 

	// Function to remove loop 
	void removeLoop(Node loop, Node head) 
	{ 
		Node ptr1 = loop; 
		Node ptr2 = loop; 

		// Count the number of nodes in loop 
		int k = 1, i; 
		while (ptr1.next != ptr2) { 
			ptr1 = ptr1.next; 
			k++; 
		} 

		// Fix one pointer to head 
		ptr1 = head; 

		// And the other pointer to k nodes after head 
		ptr2 = head; 
		for (i = 0; i < k; i++) { 
			ptr2 = ptr2.next; 
		} 

		/* Move both pointers at the same pace, 
		they will meet at loop starting node */
		while (ptr2 != ptr1) { 
			ptr1 = ptr1.next; 
			ptr2 = ptr2.next; 
		} 

		// Get pointer to the last node 
		while (ptr2.next != ptr1) { 
			ptr2 = ptr2.next; 
		} 

		/* Set the next node of the loop ending node 
		to fix the loop */
		ptr2.next = null; 
	} 


	void printList(Node node) 
	{ 
		while (node != null) { 
			System.out.print(node.data + " "); 
			node = node.next; 
		} 
	} 

	public static void main(String[] args) 
	{ 
		DL list = new DL(); 
		list.head = new Node(50); 
		list.head.next = new Node(20); 
		list.head.next.next = new Node(15); 
		list.head.next.next.next = new Node(4); 
		list.head.next.next.next.next = new Node(10); 

		head.next.next.next.next.next = head.next.next; 
		list.detectAndRemoveLoop(head); 
		System.out.println("Linked List after removing loop : "); 
		list.printList(head); 
	} 
} 

