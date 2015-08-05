class ListNode {
    int val;
    ListNode next;
    ListNode (int value) {
        val = value;
        this.next = null;
    }
}

public class CareerUp {
    public ListNode NthToLast(ListNode head, int k) {
        if (k <= 0) return null;
        ListNode slow = head;
        ListNode fast = head;
        for (int i = 0; i < k - 1; i ++) {
            if (fast == null) return null;
            fast = fast.next;
        }
        if (fast == null) return null;
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }
}