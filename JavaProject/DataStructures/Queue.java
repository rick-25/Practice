package DataStructures;
/**
 * Queue
 */
public class Queue {

    private ListNode head;
    private ListNode tail;

    private int size;

    Queue() {
        size = 0;
        head = null;
        tail = null;
    }

    public Queue(int val) {
        enQueue(val);
    }

    public int deQueue() {

        if(tail == null)
            return -1;

        size--;

        int temp = tail.val;

        if(tail.next == null)
            head = null;
        tail = tail.next;

        return temp;
    }

    public void enQueue(int val) {

        size++;

        if(head != null) {
            head.next = new ListNode(val);
            head = head.next;
        }
        else {
            head = new ListNode(val);
            tail = head;
        }
    }

    public int size() { return size; }
    public String toString() { return tail.toString(); }
}