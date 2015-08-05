public class CareerUp {
    class ListNode {
        int val;
        ListNode next;
        ListNode (int value) {
            val = value;
            this.next = null;
        }
    }
    public void deleteDups(ListNode head) {
        if (head == null || head.next == null) return;
        Hashtable table = new Hashtable();
        ListNode cur = head;
        table.put(head.val, true);
        head = head.next;
        while (head != null) {
            if (!table.containsKey(head.next)) {
                cur.next = head;
                cur = cur.next;
            }
            head = head.next;
        }
        cur.next = null;
    }
}