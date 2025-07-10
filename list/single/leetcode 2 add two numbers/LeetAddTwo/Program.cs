
  public class ListNode {
      public int val;
      public ListNode next;
      public ListNode(int val=0, ListNode next=null) {
          this.val = val;
          this.next = next;
      }
  }
 
public class Solution {

    static int givemeNumber(ListNode list){
        int i = 1;
        int number = 0;
        while(list!=null){ 
           number += list.val*i;
           i = i*10;
           list = list.next;
         }
         return number;
    }

    public static void Main(String[] args)
    {
        ListNode nodea = new ListNode(1);
        ListNode nodeb = new ListNode(6);
        ListNode nodec = new ListNode(2);
        //261
        ListNode noded = new ListNode(3);
        ListNode nodee = new ListNode(4);
        ListNode nodef = new ListNode(3);
        //343
        //sum = 604
        nodea.next = nodeb;
        nodeb.next = nodec;

        noded.next = nodee;
        nodee.next = nodef;

        ListNode sol = AddTwoNumbers(nodea, noded);
        while (sol!= null)
        {
            Console.WriteLine(sol.val);
            sol = sol.next;
        }


    }


    static ListNode AddTwoNumbers(ListNode l1, ListNode l2)
    {

        ListNode numa = l1;
        ListNode numb = l2;

        int numbera = givemeNumber(numa);
        int numberb = givemeNumber(numb);

        int sum = numbera + numberb;
        if (sum == 0) { return new ListNode(0); }


        ListNode newList = new ListNode(0);
        ListNode curr = newList;

        while (sum > 0)
        {
            int digit = sum % 10;
            curr.next = new ListNode(digit);
            curr = curr.next;
            sum = sum / 10;
        }

        return newList.next;
    }
}