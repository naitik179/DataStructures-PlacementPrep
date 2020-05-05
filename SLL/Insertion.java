import java.util.*;

class Insertion
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

	public void insertEnd(int d)
	{
		Node newnode = new Node(d);

		if(head == null)
		{
			head= newnode;
		}

		Node findlast = head;

		while(findlast.next !=null)
		{
			findlast = findlast.next;
		}

		findlast.next = newnode;
	}

	public void insertAfter(int d , int dtoadd)
	{

		Node newnode = new Node(dtoadd);

		Node findnode= head;

		while(findnode.data != d)
		{
			findnode = findnode.next;
		}
		if(findnode.next == null)
		{
			System.out.println("No Node Found");
			return;
		}
		else{
			newnode.next = findnode.next;
		  findnode.next = newnode;
		}
	}

	public void insertBefore(int d , int dtoadd)
	{
		Node newnode =new Node(dtoadd);

		Node findnode =head;
		Node prevfindnode = findnode;

		while(findnode.data != d)
		{
			prevfindnode= findnode;
			findnode = findnode.next;
		}

		if(findnode ==null || head ==null)
		{
			System.out.println("No Node found");
		}
		else{
			newnode.next = findnode;
			prevfindnode.next = newnode;
		}
	}

	public static void main(String args[])
	{
		Insertion list = new Insertion();
		list.insertBegin(1);
		list.insertAfter(1, 2);
		list.insertEnd(3);
		list.insertAfter(3,4);
		list.insertBefore(4,5);
		list.insertBegin(7);
		list.insertBefore(3, 8);
		list.printlist();
		System.out.println();
	}

}

