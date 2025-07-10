
class ListNode {

    int val;
    ListNode next;

    ListNode() {
        this.next = null;
    }

    ListNode(int value) {
        this.val = value;
    }
}

public class Program {

    public static void main(String[] args) {
        int values[] = {1, 0, 0, 2, 1, 0, 2};
        ListNode head = new ListNode(values[0]);
        ListNode headTest = head;
        for (int i = 1; i < values.length; i++) {
            headTest.next = new ListNode(values[i]);
            headTest = headTest.next;
        }

        getListSorted(head);

    }

    static void getListSorted(ListNode head) {

        ListNode zerohead = new ListNode(-1);
        ListNode onehead = new ListNode(-1);
        ListNode twohead = new ListNode(-1);
        ListNode zerotail = zerohead;
        ListNode onetail = onehead;
        ListNode twotail = twohead;

        ListNode curr = head;
        while (head != null) {
            if (head.val == 0) {
                zerotail.next = head;
                zerotail = zerotail.next;
            }
            else if (head.val == 1) {
                onetail.next = head;
                onetail = onetail.next;
            } else {
                twotail.next = head;
                twotail = twotail.next;
            }
            head = head.next;
        }

        twotail.next = null;
        onetail.next = twohead.next;
        zerotail.next = onehead.next;

        curr = zerohead.next;
        while(curr!=null){
            System.out.println(curr.val);
            curr = curr.next;
        }

    }
}
