import java.util.*;

class CircularDLL{


	Node head;

	class Node{
		int data;
		Node prev;
		Node next;

		Node(int d){
			data = d;
		}
	}


	void insertBegin(int d){

		if(head == null){
			Node newnode = new Node(d);
			newnode.next = newnode;
			newnode.prev = newnode;
			head = newnode;
		}

		else{
			Node last = head.prev;

			Node newnode = new Node(d);

			newnode.next = head;
			newnode.prev = last;
			head.prev = newnode;
			last.next = newnode;

			head = newnode;
		}
	}

	void insertEnd(int d){

		if(head == null){
			Node newnode = new Node(d);
			newnode.next = newnode;
			newnode.prev = newnode;
			head = newnode;
		}

		else{
			Node last = head.prev;

			Node newnode = new Node(d);

			newnode.next = head;
			newnode.prev = last;
			head.prev = newnode;
			last.next = newnode;

		}
	}

	void insertBefore(int d , int dtoadd){

		if(head == null){
			System.out.println("Invalid");
		}
		else if(head.data == d){
				Node newnode = new Node(dtoadd);

				Node ptr = head.prev;
				
				newnode.next = head;
				ptr.next = newnode;
				head.prev = newnode;
				newnode.prev = ptr;

				head = newnode;
		}
		else{
			Node p = head;
			int flag =0;

			while(p.next != head){
				if(p.next.data == d){
					flag =1;
					break;
				}
				p = p.next;
			}

			if(flag == 0){
				System.out.println("No Node Found with value " + d);
			}
			else{
				Node newnode = new Node(dtoadd);

				if(p == head){
					Node preptr = head.prev;

					newnode.next =  p;
					preptr.next = newnode;
					newnode.prev = preptr;
					head.prev = newnode;

					head = newnode;
				}
				else{
				Node ptr = p.next;
				
				newnode.next = p.next;
				ptr.prev = newnode;
				p.next = newnode;
				newnode.prev = p;
				}

			}
		}
	}

	void insertAfter(int d , int dtoadd){

		if(head == null){
			System.out.println("Invalid");
		}
		else if(head.data == d){
				Node newnode = new Node(dtoadd);

				Node ptr = head.next;
				
				newnode.next = ptr;
				ptr.prev = newnode;
				head.next = newnode;
				newnode.prev = head;
		}
		else{
			Node p = head;
			int flag =0;

			while(p.next != head){
				// important line to add first in the while loop and not in the last
				p = p.next;
				if(p.data == d){
					flag =1;
					break;
				}
			}

			if(flag == 0){
				System.out.println("No Node Found with value " + d);
			}
			else{
				Node newnode = new Node(dtoadd);

				if(p.next == head){

					newnode.next =  head;
					p.next = newnode;
					newnode.prev = p;
					head.prev = newnode;

				}
				else{
				Node ptr = p.next;
				
				newnode.next = ptr;
				ptr.prev = newnode;
				p.next = newnode;
				newnode.prev = p;
				}

			}
		}
	}

	void printlist(){

		Node p = head;

		do{
			System.out.print(p.data+"<=>");
			p = p.next;
		}
		while(p!=head);

		System.out.println();
	}

	public static void main(String args[]){
		CircularDLL list = new CircularDLL  ();
		list.insertEnd(6);
		list.insertBegin(1);
		list.insertBegin(2);
		list.insertEnd(4);

		list.printlist(); 		 	// 2<=>1<=>6<=>4<=>

		list.insertAfter(4, 5);
		list.printlist(); 			// 2<=>1<=>6<=>4<=>5<=>
		list.insertAfter(2 , 4);
		list.printlist();				// 2<=>4<=>1<=>6<=>4<=>5<=>

		list.insertBefore(2, 0);
		list.printlist();  			// 0<=>2<=>4<=>1<=>6<=>4<=>5<=>


	}
}