/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {
    
    public ListNode reverse(ListNode head){
        ListNode prev = null;   
        ListNode nextnode = null;
        ListNode curr = head; 
      
        while (curr!=null) { 
            nextnode = curr.next; 
            curr.next = prev; 
            prev = curr; 
            curr = nextnode; 
        } 
        return prev; 
    }
    public ListNode reverseBetween(ListNode A, int m, int n) {
        
        if(m == n)
        {
            return A;
        }
        ListNode revs = null, revs_prev = null; 
        ListNode revend = null, revend_next = null;
        
        int i = 1;
        ListNode curr = A;
        while(curr!=null && i<=n){
            
            if(i<m){
                revs_prev = curr;
            }
            if(i == m){
                revs = curr;
            }
            if(i == n){
                revend = curr;
                revend_next = curr.next;
            }
            
            curr = curr.next;
            i++;
        }
        
        revend.next = null;
        
        revend = reverse(revs);
        
        if(revs_prev != null){
            revs_prev.next = revend;
        }
        else{
            A = revend;
        }
        
        revs.next = revend_next;
        
        return A;
        
    }
}
