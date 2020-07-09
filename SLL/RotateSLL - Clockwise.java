/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode A, int B) {
        
        ListNode current = A;
    int size = 1;
    while(null != current.next){
        size++;
        current = current.next;
    }
    current.next = A;
    
    int count = size - (B % size);
    while(count-- > 0){
        current = current.next;
    }
    ListNode start = current.next;
    current.next = null;
    return start;
    }
}
