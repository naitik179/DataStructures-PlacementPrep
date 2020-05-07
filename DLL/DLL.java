	class DLL {
  Node head;

    class Node { 
        int data; 
        Node prev; 
        Node next; 
  
        // Constructor to create a new node 
        // next and prev is by default initialized as null 
        Node(int data) { this.data = data; } 
    } 


	public void insertBegin(int d){

		Node newnode  = new Node(d);

		newnode.prev = null;

		if(head==null)
		{
			newnode.next= null;
			
			head = newnode;
			return;
		}
		else{
			newnode.next = head;
			head = newnode;
			return;
		}
	}

	public void insertEnd(int d){

		Node newnode = new Node(d);
		newnode.next = null;

		if(head==null){
			//this is the first node
			newnode.prev = null;
			head = newnode;
			return ;
		}
		else{
			Node ptr = head;

			while(ptr.next != null){
				ptr = ptr.next;
			}

			// ******** Important  Step *******
			newnode.prev = ptr;
			ptr.next = newnode;

		}
	}

	public void InsertAfter(int d , int dtoadd){

		int found = 0;
		Node ptr = head;
		if(head == null){
			System.out.println("No Node found ");
			return;
		}

		else{

			while(ptr != null)
			{
				if(ptr.data == d)
				{
					found =1;
					break;
				}
				ptr = ptr.next;
			}

			if(found == 1)
			{
			// last node is encountered
			if(ptr.next == null){

				Node newnode = new Node(dtoadd);
				newnode.next = null;

				newnode.prev = ptr;
				ptr.next = newnode;
			}
			else{
				Node newnode = new Node(dtoadd);

				// ********* Important **********
				newnode.next = ptr.next;
				(ptr.next).prev = newnode;
				newnode.prev = ptr;
				ptr.next = newnode;
			}
			}
			else{
				System.out.println("No node found");
			}


		}
	}

	public void printlist(){

		
		if(head == null){
			System.out.println("No List available ");
		}
		else{
			Node ptr =head;

			while(ptr != null){
				System.out.print(ptr.data + "<->");
				ptr = ptr.next;
			}
		}

		System.out.println();
	}

	public void DeleteBegin(){

		Node todelete = head;

		if(head == null){
			System.out.println("No node to delete ");
		}
		else if(todelete.next == null){
			// first node 
			head = null;
		}
		else{
		
			head = head.next;
			todelete.next = null;
			head.prev = null;

			printlist();
		}
	}

	public void DeleteEnd(){

		Node todelete = head;

		if(head == null){
			System.out.println("No node to delete ");
		}

		else if(todelete.next == null){
			// firstnode to delete 
			head = null;
			return;
		}

		else{
			Node ptr = head;
			while(ptr.next.next != null){
				ptr = ptr.next;
			}
			// deletin the last node 
			ptr.next = null;
		}
			printlist();
	}


	public static void main(String args[]){

		Main dll = new Main();

		dll.insertBegin(1);
		dll.insertBegin(3);

		// 3<->1<->
		dll.printlist();
		dll.insertEnd(2);
		dll.insertEnd(6);
		// 3<->1<->2<->6<->
		dll.printlist();
		dll.DeleteEnd();
		dll.InsertAfter(1 , 2);
		// 3<->1<->2<->2<->
		dll.printlist();

		// No Node found
		dll.InsertAfter(5 , 3);

	}
}