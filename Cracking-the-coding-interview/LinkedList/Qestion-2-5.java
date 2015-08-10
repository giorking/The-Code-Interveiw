/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;      
 *     }
 * }
 */
public class CareerUp {
    public ListNode addLists(ListNode l1, ListNode l2, int carry) {
        if (l1 == null && l2 == null && carry == 0) {
            return null;
        }
        int value = carry;
        if (l1 != null) {
            value += l1.val;
        }
        if (l2 != null) {
            value += l2.val;
        }
        ListNode res = new ListNode(value % 10);
        ListNode tail = addLists(l1 == null ? null : l1.next,
                l2 == null ? null: l2.next,
                value >= 10 ? 1 : 0);
        res.next = tail;
        return res;
    }
}

//follow up, I hava a idea, we can reverse the ListNode, then we can add them;