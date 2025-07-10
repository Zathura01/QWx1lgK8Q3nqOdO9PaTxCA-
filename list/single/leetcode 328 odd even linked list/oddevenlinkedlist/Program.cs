  public class ListNode {
      public int val;
      public ListNode next;
      public ListNode(int val=0, ListNode next=null) {
          this.val = val;
          this.next = next;
      }
  }

public class Solution
{
    static ListNode OddEvenList(ListNode head)
    {
        ListNode curr = head;
        ListNode temp = curr;

        int oddheadlength = 0;
        int evenheadlength = 0;
        while (head != null)
        {
            if (head.val % 2 != 0)
            {
                oddheadlength += 1;
            }
            else
            {
                evenheadlength += 1;
            }
            head = head.next;
        }
        int[] odds = new int[oddheadlength];
        int[] evens = new int[evenheadlength];
        int j = 0;  // to track odds and update in array
        int k = 0; //to track evens and update in array
        head = curr;
        while (head != null)
        {
            if (head.val % 2 != 0)
            {
                odds[j] = head.val;
                j++;
            }
            else
            {
                evens[k] = head.val;
                k++;
            }
            head = head.next;
        }


        curr = temp; // reset to start of list again

        // Write odd values first
        foreach (int odd in odds)
        {
            curr.val = odd;
            curr = curr.next;
        }

        // Then write even values
        foreach (int even in evens)
        {
            curr.val = even;
            curr = curr.next;
        }

        head = temp;

        while (temp != null)
        {
            Console.Write(temp.val);
            temp = temp.next;
        }

        return head;

    }
    public static void Main(string[] args)
    {
        ListNode nodea = new ListNode(3);
        ListNode nodeb = new ListNode(4);
        ListNode nodec = new ListNode(2);
        ListNode noded = new ListNode(6);
        ListNode nodee = new ListNode(34);
        ListNode nodef = new ListNode(9);
        ListNode nodeg = new ListNode(21);
        ListNode ourList = nodea;
        nodea.next = nodeb;
        nodeb.next = nodec;
        nodec.next = noded;
        noded.next = nodee;
        nodee.next = nodef;
        nodef.next = nodeg;

        ListNode nodes = OddEvenList(ourList);
        while (ourList != null)
        {
            Console.WriteLine(ourList.val);
            ourList = ourList.next;
        }
    }
}