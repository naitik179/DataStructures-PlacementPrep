/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {
    public int lPalin(ListNode A) {
        
        if(A == null){
            return 1;
        }
        int length = 0;
        ListNode p = A;
        
        while(p!=null){
            p = p.next;
            length++;
        }
        
        p = A;
        if(length == 1){
            return 1;
        }
        int half = (length+1)/2;
        ListNode q = A;
        
        for(int i=0;i<half;i++){
            q = q.next;
        }
        
        ListNode r = q.next;
        q.next = null;
        ListNode m;
        while(r != null) {
            m = r.next;
            r.next = q;
            q = r;
            r = m;
        }
        
        while(q != null && p != null) {
            if(p.val == q.val) {
                q = q.next;
                p = p.next;
            }else {
                return 0;
            }
            
        }
        return 1;
    }
}
