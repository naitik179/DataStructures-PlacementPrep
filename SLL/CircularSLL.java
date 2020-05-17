class CircularSLL {

		Node tail;
  
	class Node{

		int data;
		Node next;

		Node(int x){
			data =x;
			next= null;
		}
	}

	void insertBegin(int d){

		Node newnode = new Node(d);

		if(tail == null){
			tail = newnode;
			tail.next  = tail;
		}

		else{
			newnode.next  = tail.next;
			tail.next = newnode;
		}

	}

	void insertEnd(int d){

		Node newnode = new Node(d);

		if(tail == null){
			tail = newnode;
			tail.next  = tail;
		}
		else{
			newnode.next = tail.next;
			tail.next = newnode;
			tail = newnode;
		}
	}

	void printlist(){

		if(tail == null){
			System.out.println("No Node in the list");
			return;
		}
		else{

			Node p = tail.next;

			do{
				System.out.print(p.data + "->");
				p = p.next;
			}
			while(p!=tail.next);
		}
		System.out.println();
	}

	void addBeforeNode(int d , int dtoadd){

		if(tail == null){
			return;
		}
		else{

		Node p = tail.next;
		int flag=0;
		do{
			if((p.next).data == d){
				flag=1;
				break;
			}
			p = p.next;
		}
		while(p!=tail.next);

		if(flag==0){
			System.out.println("No Node found");
		}
		else{
			  Node newnode = new Node(dtoadd);

				newnode.next = p.next;
				p.next = newnode;
		}
		}
	}


	void addAfterNode(int d , int dtoadd){

		if(tail == null){
			return;
		}
		else{

		Node p = tail.next;
		int flag=0;
		do{
			if(p.data == d){
				flag=1;
				break;
			}
			p = p.next;
		}
		while(p!=tail.next);

		if(flag==0){
			System.out.println("No Node found");
		}
		else{
			Node newnode = new Node(dtoadd);

			if(p == tail){
				newnode.next = tail.next;
				tail.next = newnode;
				tail = newnode;
			}
			else{
				newnode.next = p.next;
				p.next = newnode;

			}
		}
		}
	}

	void DeleteBegin(){

		if(tail == null){
			System.out.println("No Node to delete");
		}
		else{
			if(tail.next == tail){
				tail = null;
				return;
			}

			else{
				Node p = tail.next;
				tail.next = p.next; 
				return;
			}
		}
	}

	void DeleteEnd(){

		if(tail == null){
			System.out.println("No Node to delete");
		}
		else{
			if(tail.next == tail){
				tail = null;
				return;
			}
			else{
				Node p = tail.next;

				do{
					p = p.next;
				}
				while(p.next !=tail);

				p.next = tail.next;
				tail = p;
			}
		}

	}

	public static void main(String[] args) 
{ 
    CircularSLL list = new CircularSLL();
		
    list.insertBegin(4); 
    list.insertBegin(2); 
    list.insertEnd(8); 
    list.insertEnd(12);
		list.printlist();  //        2->4->8->12->
		list.addBeforeNode(2, 1);
		list.printlist();  //        1->2->4->8->12->
		list.addAfterNode(12 , 0);
		list.printlist();  //        1->2->4->8->12->0->

		list.DeleteBegin();
		list.printlist();       //   2->4->8->12->0->

		list.DeleteEnd();
		list.printlist();    //      2->4->8->12->
 
} 
}