class ReverseSLL
{
	Node head;

	static class Node{
		int data;
		Node next;

		Node(int d)
		{
			data = d;
			next = null;
		}
	}

	public void printlist()
	{
		Node n = head;
		while(n!=null)
		{
			System.out.print(n.data +"->");
			n = n.next;
		}
	}
	public void insertBegin(int d)
	{
		Node newnode = new Node(d);

		if(head == null)
		{
			head = newnode;
		}
		else{
			newnode.next = head;
			head= newnode;
		}
	}

	public void reverse(){
        
        Node current  = head;
        
        if(head == null){
            System.out.println("No node to reverse");
        }
        else{
            Node prev = null;
            Node nextnode = null;

            while(current != null){
                nextnode = current.next;
                current.next = prev;
                prev = current;
                current = nextnode;
            }
            head = prev;
        }
    }

	public static void main(String args[])
	{
		ReverseSLL list = new ReverseSLL();
        list.insertBegin(1);
        list.insertBegin(2);
        list.insertBegin(3);
        list.insertBegin(4);
        list.printlist();
        System.out.println();
        list.reverse();
		list.printlist();		
	}

}