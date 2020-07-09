/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode A) {
        
        if(A == null){
            return null;
        }
        ListNode curr = A;
        
        while(curr != null){
            ListNode temp = curr;
            
            while(temp != null && curr.val == temp.val){
                temp = temp.next;
            }
            
            curr.next = temp;
            curr = curr.next;
        }
        
        return A;
    }
}
