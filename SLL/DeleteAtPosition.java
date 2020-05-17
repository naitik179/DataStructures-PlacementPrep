class Solution
{
    public static Node deleteAtPosition(Node head, int pos)
    {
        
        int n=1;    
        Node pp = head; // calculating the length of the CSLL
        while(pp.next!=head){
            n++;
            pp=pp.next;
        }

        // for pos == 1
        if(pos == 1){
            
            Node p = head;
            head = p.next;
            Node gg = head;

            // now connecting last to the 2nd element 
            while(gg.next != p){
                gg= gg.next;
            }
            gg.next = p.next;
            
        }
        

        // deletion at last pos 
        else if(pos == n)
        {
            Node ss =head;
            while(ss.next.next!=head){
            ss=ss.next;
            }
            ss.next = head;
        }
        
        // deleting at any intermediate posiion
        else{
            Node ptr = head;
            for(int i=1;i<pos-1;i++){
            ptr = ptr.next;
            }
            ptr.next = ptr.next.next;
        }
        
        return head;
    }
}