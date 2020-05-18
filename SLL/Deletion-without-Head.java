/*
	Deletion of the node whose pointer is given and no head is given can be done by
	Transfering the data of the next Node in this Node and then Deleting the Next Node in the sequence


	This cant work if we want to delete the last node of the SLL

*/


class Deletion-without-Head { 

	static Node head; 

	static class Node { 

		int data; 
		Node next; 

		Node(int d) { 
			data = d; 
			next = null; 
		} 
	} 

	void printList(Node node) { 
		while (node != null) { 
			System.out.print(node.data + " "); 
			node = node.next; 
		} 
	} 

	void deleteNode(Node node) { 
		Node temp = node.next; 
		node.data = temp.data; 
		node.next = temp.next; 
		System.gc(); 

	} 

	public static void main(String[] args) { 
		Deletion-without-Head list = new Deletion-without-Head(); 
		list.head = new Node(1); 
		list.head.next = new Node(12); 
		list.head.next.next = new Node(1); 
		list.head.next.next.next = new Node(4); 
		list.head.next.next.next.next = new Node(1); 

		System.out.println("Before Deleting "); 
		list.printList(head); 

		list.deleteNode(head); 
		System.out.println(""); 
		System.out.println("After deleting "); 
		list.printList(head); 
	} 
} 
