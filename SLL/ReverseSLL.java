class ReverseSLL
{
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
}