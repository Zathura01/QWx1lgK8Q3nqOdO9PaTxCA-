import java.util.Random;

class ListNode{
    int val;
    ListNode next;
    ListNode(int val){
        this.val = val;
        this.next = null;
    }
}

public class Program {
    public static void main(String args[]){
         int values[] = {5, 4, 3,2,5,7,2};
         ListNode list = new ListNode(values[0]);
         ListNode head = list;
         for(int i = 1; i<values.length; i++){
            list.next = new ListNode(values[i]);
            list = list.next;
         }

         Random rand = new Random();
         int n = rand.nextInt(0, values.length);
         removefunction(head, n);
         
    }

    static void removefunction(ListNode head, int n){
        int lengthlist = 0;
        ListNode curr = head;
        while(curr!=null){
            lengthlist++;
            curr = curr.next;
        }
        ListNode list = head;
        for (int i = 0; i < lengthlist-n-1; i++) {
            list = list.next;
        }

        list.next = list.next.next;
        
        System.out.println("Removed "+n+"th Node From The End of List");
        while(head!=null){
            System.out.println(head.val);
            head = head.next;
        }

    }
}
