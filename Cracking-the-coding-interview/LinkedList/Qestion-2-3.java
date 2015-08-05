class ListNode {
    int val;
    ListNode next;
    ListNode (int value) {
        val = value;
        this.next = null;
    }
}

public class CareerUp {
    public boolean deleteNode(ListNode node) {
        if (node == null || node.next == null) return false;
        node.val = node.next.val;
        node.next = node.next.next;
        return  true;
    }
}