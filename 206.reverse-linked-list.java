/*
 * @lc app=leetcode id=206 lang=java
 *
 * [206] Reverse Linked List
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

 // Reference: https://ithelp.ithome.com.tw/articles/10224711
class Solution {
    public ListNode reverseList(ListNode head) {
        return recursive(head);
    }

    public ListNode recursive(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        // the root node is still be appointed at by the head
        ListNode root = recursive(head.next);

        // use head.next.next to let the next node to point at
        // back it (notice that there is a cycle between two nodes)
        head.next.next = head;

        // destroy the cycle
        head.next = null;

        return root;
    }

    public ListNode iterateList(ListNode head) {
        ListNode newHead = null;
        while (head != null) {
            ListNode temp = head.next;
            head.next = newHead;
            newHead = head;
            head = temp;
        }

        return newHead;
    }
}
// @lc code=end

