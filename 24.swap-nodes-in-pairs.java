/*
 * @lc app=leetcode id=24 lang=java
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// Reference: https://skyyen999.gitbooks.io/-leetcode-with-javascript/content/questions/24md.html
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        ListNode cur = head;

        while (cur != null && cur.next != null) {
            ListNode nextPair = cur.next.next;
            cur.next.next = cur;
            prev.next = cur.next;
            cur.next = nextPair;

            prev = cur;
            cur = cur.next;
        }

        return dummy.next;
    }
}


 // Solution is not very proper to the question request
// class Solution {
//     public ListNode swapPairs(ListNode head) {
//         if (head == null || head.next == null) {
//             return head;
//         }

//         ListNode prev = head;
//         ListNode cur = head.next;
//         while(prev != null && cur != null) {
//             int temp = prev.val;
//             prev.val = cur.val;
//             cur.val = temp;

//             if (cur.next == null || cur.next.next == null) {
//                 break;
//             }

//             prev = cur.next;
//             cur = cur.next.next;
//         }

//         return head;
//     }
// }
// @lc code=end

