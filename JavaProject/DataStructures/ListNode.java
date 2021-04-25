package DataStructures;

public class ListNode {
    public int val;
    public ListNode next;
    public ListNode prev;

    public ListNode(int val) {
        this.val = val;
        next = prev = null;
    }

    public String toString() {
        ListNode head = this;
        String out = "[";
        while (head != null) {
            out += String.format("%d%c", head.val, (head.next != null) ? ',' : ']');
            head = head.next;
        }
        return out;
    }

    public static ListNode toList(int arr[]) {
        if(arr.length == 0)
            return null;
            
        ListNode head = new ListNode(arr[0]);
        ListNode r = head;
        for (int i = 1; i < arr.length; i++) {
            r.next = new ListNode(arr[i]);
            r = r.next;
        }
        return head;
    }

    public int length() {
        int i = 0;
        ListNode temp = this;
        while (temp != null) {
            i++;
            temp = temp.next;
        }
        return i;
    }
}
