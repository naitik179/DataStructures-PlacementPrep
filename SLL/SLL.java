import java.util.*;

class SLL
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

		if(findnode.next ==null || head ==null)
		{
			System.out.println("No Node found");
			return;
		}
		else{
			newnode.next = findnode;
			prevfindnode.next = newnode;
		}
	}
	
	
	public void DeleteNodeByData(int d)
	{

		Node todelete = head;
		Node prev = null;

		//checking if the node to delete is the head
		if(todelete != null && todelete.data == d)
		{
			head = head.next;
			return ;
		}

		// traversing to find the node to delete
		while(todelete.next !=null && todelete.data != d)
		{
			prev = todelete;
			todelete= todelete.next;
		}

		prev.next = todelete.next;

	}

	public void DeleteEnd()
	{
		Node todelete = head;
		Node prev =null;

		if(head == null)
		{
			System.out.println("No node to Delete ");
			return;
		}

		//traversing the SLL
		while(todelete.next !=null)
		{
			prev = todelete;
			todelete= todelete.next;
		}

		prev.next =null;
	}

	public void DeleteByPosition(int pos)
	{
		Node prev = head;

		//checking if SLL is empty
		if(head == null)
		{
			System.out.println("No SLL");
		}

		// checking if head is to be deleted 0 indexed
		if(pos == 0)
		{
			head = head.next;
		}

		// getting the length of the SLL
		Node len = head;
		int count = 1;
		while(len.next != null)
		{
			count++;
			len = len.next;
		}
		
		System.out.println("Count is" + count);
		if(pos < count)
		{
			// traversing to the previous position
			for(int i=0;i<pos-1;i++)
			{
				prev = prev.next;
			}

			//deleting the next node so next.next
			prev.next = prev.next.next;
		}
		else{
			System.out.println("Pos is greater than Length to Delete");
			return;
		}
	}

	public static void main(String args[])
	{
		SLL list = new SLL();
		list.insertBegin(1);
		list.insertEnd(3);
		list.insertAfter(1, 2);
		list.insertEnd(4);
		list.insertBefore(3,5);
		// 1>2>5>3>4
		list.printlist();
		System.out.println();
		list.DeleteNodeByData(5);
		// 1>2>3>4
		list.printlist();
		System.out.println();
		list.DeleteByPosition(1);
		//1>3>4
		list.printlist();
		System.out.println();
		
		
	}

}