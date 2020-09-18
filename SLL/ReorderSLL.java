/*

Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→…
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

Note: It is recommended do this in-place without altering the nodes' values.

Example 1:

Input:
LinkedList: 1->2->3
Output: 1 3 2
Example 2:

Input:
LinkedList: 1->7->3->4
Output: 1 4 7 3.

*/
class gfg {
    public Node reverselist(Node node) 
    { 
        Node prev = null, curr = node, next; 
        while (curr != null) { 
            next = curr.next; 
            curr.next = prev; 
            prev = curr; 
            curr = next; 
        } 
        node = prev; 
        return node; 
    } 
    Node reorderlist(Node head) {
        // Your code here
        Node slow = head;
        Node fast = head;
        
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        Node head1 = head;
        Node head2 = slow.next;
        slow.next = null;
        
        head2 = reverselist(head2);
        
        head = new Node(0);
        Node curr = head;
        while(head1!=null || head2!=null){
            if(head1!=null){
                curr.next = head1;
                curr = curr.next;
                head1 = head1.next;
            }
            if (head2 != null) { 
                curr.next = head2; 
                curr = curr.next; 
                head2 = head2.next; 
            } 
        }
        
        head = head.next;
        return head;
    }
}
