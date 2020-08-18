class GfG
{
    // Function to find the nth node from end in the linked list
    // head: head of the linked list
    // n: nth node from end to find
    int getNthFromLast(Node head, int n)
    {
    	// Your code here	
    	
    	if(head == null){
    	    return -1;
    	}
    	else{
    	    Node ptr = head;
    	    int size = 1;
    	    
    	    while(ptr.next != null){
    	        ptr = ptr.next;
    	        size++;
    	    }
    	    
    	    if(n > size){
    	        return -1;
    	    }
    	    
    	    ptr.next = head;
    	    int count = size - ( size % n);
    	    int count1= 1;
    	    Node ans = head;
    	    while(count1 != count){
    	        ans = ans.next;
    	        count1++;
    	    }
    	    
    	    return ans.data;
    	}
    }
}
