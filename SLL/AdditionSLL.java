class AdditionSLL { 

	static Node head1, head2; 
	static class Node { 

		int data; 
		Node next; 

		Node(int d) { 
			data = d; 
			next = null; 
		} 
	} 

	Node addTwoLists(Node first, Node second) {
        
        Node temp = null;
        Node ptr = null;
        Node heads = null;
        int sum =0;
        int carry = 0;
        int ans = 0;
        
        while(first!=null || second!=null){
            
            ans = carry +  (first!=null ? first.data : 0 ) + (second!=null ? second.data : 0);
            
            if(ans >= 10){
                carry = 1;
            }
            else{
                carry =0;
            }
            
            sum = ans%10;
            temp = new Node(sum);
            
            if(heads == null){
                heads = temp;
            }
            else{
                ptr.next = temp;
            }
            
            ptr = temp;
            
            if(first !=null){
                first = first.next;
            }
            
            if(second !=null){
                second = second.next;
            }
            
        }
        
        if(carry > 0){
            temp.next = new Node(carry);
        }
        return heads;
        
    }

	void printList(Node head) { 
		while (head != null) { 
			System.out.print(head.data + " "); 
			head = head.next; 
		} 
		System.out.println(""); 
	} 

	public static void main(String[] args) { 
		AdditionSLL list = new AdditionSLL(); 

		// creating first list 
		list.head1 = new Node(7); 
		list.head1.next = new Node(5); 
		list.head1.next.next = new Node(9); 
		list.head1.next.next.next = new Node(4); 
		list.head1.next.next.next.next = new Node(6); 
		System.out.print("First List is "); 
		list.printList(head1); 

		// creating seconnd list 
		list.head2 = new Node(8); 
		list.head2.next = new Node(4); 
		System.out.print("Second List is "); 
        list.printList(head2); 
        
		Node rs = list.addTwoLists(head1, head2); 
		System.out.print("Resultant List is "); 
		list.printList(rs); 
	} 
} 

