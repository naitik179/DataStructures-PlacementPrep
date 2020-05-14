class LoopLength { 
	Node head;

	class Node { 
		int data; 
		Node next; 
		Node(int d) 
		{ 
			data = d; 
			next = null; 
		} 
	} 

	
	public void push(int new_data) 
	{ 
	
		Node new_node = new Node(new_data);
		new_node.next = head; 
		head = new_node; 
    } 
    
    int countlooplength(Node p){

        Node temp =p;
        int counter = 1;
        temp = temp.next;

        while(temp!=p){
            counter++;
            temp = temp.next;
        }

        return counter;
    }

	void detectLoop() 
	{ 
        int flag=0;
        int l=0;
		Node slow_p = head, fast_p = head; 
		while (slow_p != null && fast_p != null && fast_p.next != null) { 
			slow_p = slow_p.next; 
			fast_p = fast_p.next.next; 
			if (slow_p == fast_p) { 
                l = countlooplength(slow_p);
                
                flag =1;
                break;
			} 
        }

        if(flag == 1)
        {
            System.out.println("Found loop of length " + l);
        }
        else{

            System.out.println("No Loop found");

        }
	} 

	public static void main(String args[]) 
	{ 
		LoopLength llist = new LoopLength(); 

		llist.push(20); 
		llist.push(4); 
		llist.push(15); 
		llist.push(10); 

		llist.head.next.next.next.next = llist.head; 
		llist.detectLoop(); 
	} 
} 

