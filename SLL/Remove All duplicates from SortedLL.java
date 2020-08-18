class LinkedList 
{ 
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
} 
